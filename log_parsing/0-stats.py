#!/usr/bin/python3
"""
0-stats module

This module does file statistics/analysis tasks.
"""
import sys
import signal

total_file_size = 0
status_codes = {
	200: 0,
	301: 0,
	400: 0,
	401: 0,
	403: 0,
	404: 0,
	405: 0,
	500: 0
}
line_count = 0

def print_stats():
	"""Print the current statistics"""
	print(f"File size: {total_file_size}")
	for code in sorted(status_codes.keys()):
		if status_codes[code] > 0:
			print(f"{code}: {status_codes[code]}")

def signal_handler(sig, frame):
	"""Handle keyboard interrupt (CTRL + C)"""
	print_stats()
	sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)

def parse_line(line):
    global total_file_size, line_count
    try:
        parts = line.strip().split()
        if len(parts) < 2:
            return
        file_size = int(parts[-1])
        status_code = int(parts[-2])
        total_file_size += file_size
        if status_code in status_codes:
            status_codes[status_code] += 1
        line_count += 1
    except (ValueError, IndexError):
        pass

def main():
	"""Main function to read stdin line by line"""
	global line_count
	
	for line in sys.stdin:
		parse_line(line)
		
		if line_count % 10 == 0 and line_count > 0:
			print_stats()
	
	# Always print final stats (including empty input)
	print_stats()

if __name__ == "__main__":
	main()

