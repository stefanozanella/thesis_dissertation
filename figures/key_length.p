set terminal postscript eps enhanced color font 'Helvetica,10'
set output "key_length.eps"
set xlabel "Key size"
set ylabel "Hash function computation time (s)"
plot "key_size_sha256.dat" using 1:2 title "SHA-256" with linespoint, \
  "key_size_sha3_224.dat" using 1:2 title "SHA3-224" with linespoint, \
  "key_size_sha3_256.dat" using 1:2 title "SHA3-256" with linespoint
