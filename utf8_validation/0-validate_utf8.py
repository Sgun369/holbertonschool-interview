#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """ determines if a given data set represents a valid UTF-8 encoding"""
    # Number of bytes in the current UTF-8 character
    num_bytes = 0

    # Masks to check the most significant bits of a byte
    mask1 = 1 << 7
    mask2 = 1 << 6

    # Iterate over each integer (byte) in the data list
    for byte in data:

        # Mask to get the 8 least significant bits
        byte = byte & 0xFF

        if num_bytes == 0:
            # Determine the number of bytes in the UTF-8 character
            mask = 1 << 7
            while mask & byte:
                num_bytes += 1
                mask = mask >> 1

            # 1-byte characters are the same as ASCII
            if num_bytes == 0:
                continue

            # If the number of bytes is more than 4 or less than 2 (invalid
            # scenarios)
            if num_bytes == 1 or num_bytes > 4:
                return False
        else:
            # For the remaining bytes, the most significant bits should be '10'
            if not (byte & mask1 and not (byte & mask2)):
                return False
        # Decrement the byte count for the current UTF-8 character
        num_bytes -= 1

    # If num_bytes is not zero, it means we have an incomplete multi-byte
    # character
    return num_bytes == 0
