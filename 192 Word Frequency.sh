# Read from the file words.txt and output the word frequency list to stdout.
# Replace white spaces in words.txt, sort, keep unique entries, sort numerically and then reverse for descending frequency
tr -s ' ' '\n' < words.txt | sort | uniq -c | sort -nr | awk '{print $2" "$1}'
