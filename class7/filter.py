from mpi4py import MPI
from PIL import Image, ImageFilter
import sys

def apply_filter(image_part):
    return image_part.filter(ImageFilter.EMBOSS)

def divide_image(image, num_parts):
    width, height = image.size
    part_height = height // num_parts
    parts = []

    for i in range(num_parts):
        upper = i * part_height
        lower = (i + 1) * part_height if i != num_parts -1 else height
        part = image.crop((0, upper, width, lower))
        parts.append(part)
    return parts

def reassemble_image(parts, width, height):
    new_image = Image.new("RGB", (width, height))
    y_offset = 0
    for part in parts:
        new_image.paste(part, (0, y_offset))
        y_offset += part.size[1]
    return new_image

def main():
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    comm_size = comm.Get_size()

    if len(sys.argv) != 2:
        sys.exit(f"Usage: {sys.argv[0]} <name of image>")

    if rank == 0:
        image = Image.open(sys.argv[1])
        width, height = image.size
        image_parts = divide_image(image, comm_size)
    else:
        image_parts = None
        width = None
        height = None

    width = comm.bcast(width, root=0)
    height = comm.bcast(height, root=0)

    image_part = comm.scatter(image_parts, root=0)
    filtered_part = apply_filter(image_part)
    filtered_parts = comm.gather(filtered_part, root=0)

    if rank == 0:
        filtered_image = reassemble_image(filtered_parts, width, height)
        filtered_image.save(f"{sys.argv[1]}_filtered.png")

if __name__ == "__main__":
    main()
