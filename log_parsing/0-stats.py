#!/usr/bin/python3
"""Log parsing"""
import sys
import signal

total_size = 0
status_counts = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}
line_count = 0


def print_stats():
    """Prints the current statics"""
    print("File size: {}".format(total_size))
    for status_code in sorted(status_counts.keys()):
        if status_counts[status_code] > 0:
            print("{}: {}".format(status_code, status_counts[status_code]))


def signal_handler(sig, frame):
    """Handles the interrupt ssignal to print the statistics"""
    print_stats()
    sys.exit(0)


# Register the signal handler for keyboard iterruption
signal.signal(signal.SIGINT, signal_handler)

try:
    for line in sys.stdin:
        parts = line.split()
        if len(parts) < 9:
            continue

        ip_address = parts[0]
        date = parts[3] + ' ' + parts[4]
        request = ' '.join(parts[5:8])
        status_code = parts[8]
        file_size = parts[9]

        # Validate the log format
        if not (request.startswith('"GET /projects/260')
                and request.endswith('HTTP/1.1"')):
            continue

        # Update the total file size
        try:
            total_size += int(file_size)
        except ValueError:
            continue

        # Update the status code count
        if status_code in status_counts:
            status_counts[status_code] += 1

        line_count += 1

        # Print statistics every 10 lines
        if line_count % 10 == 0:
            print_stats()

except Exception as e:
    print("ERROR:", str(e))

print_stats()
