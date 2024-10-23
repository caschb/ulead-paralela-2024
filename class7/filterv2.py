from mpi4py import MPI
from PIL import Image, ImageFilter
import numpy as np
import sys

def apply_filter(image_part):
    return image_part.filter(ImageFilter.EMBOSS)

def divide_image(image, num_parts, overlap):
    width, height = image.size
    part_height = height // num_parts
    parts = []
    
    for i in range(num_parts):
        upper = max(0, i * part_height - overlap)
        lower = min(height, (i + 1) * part_height + overlap)
        part = image.crop((0, upper, width, lower))
        parts.append((part, upper, lower))
    
    return parts

def reassemble_image(parts, width, height, overlap):
    new_image = Image.new('RGB', (width, height - overlap * len(parts)))
    y_offset = 0
    
    for part, original_upper, original_lower in parts:
        part_height = original_lower - original_upper
        cropped_part = part.crop((0, overlap + original_upper - original_upper, width, original_lower - original_upper - overlap))
        new_image.paste(cropped_part, (0, y_offset))
        y_offset += cropped_part.size[1]
    
    return new_image

def main():
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()
    overlap = 10

    if len(sys.argv) != 2:
        sys.exit(f"Usage: {sys.argv[0]} <name of image>")

    if rank == 0:
        image = Image.open(sys.argv[1])
        width, height = image.size

        image_parts = divide_image(image, size, overlap)
    else:
        image_parts = None
        width = None
        height = None

    width = comm.bcast(width, root=0)
    height = comm.bcast(height, root=0)

    image_part_info = comm.scatter(image_parts, root=0)
    image_part, upper, lower = image_part_info

    filtered_part = apply_filter(image_part)

    filtered_parts = comm.gather((filtered_part, upper, lower), root=0)

    if rank == 0:
        filtered_image = reassemble_image(filtered_parts, width, height)
        filtered_image.save(f"{sys.argv[1]}_filtered.png")

if __name__ == "__main__":
    main()
