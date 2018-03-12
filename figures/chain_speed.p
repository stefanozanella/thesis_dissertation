set terminal postscript eps enhanced color font 'Helvetica,10'
set output "chain_speed.eps"
set xlabel "Chain length"
set ylabel "Chain computation time (s)"
set logscale x
plot "chain_speed_80_sha_256.dat" using 1:2 title "SHA-256" with linespoint, \
  "chain_speed_80_sha3_224.dat" using 1:2 title "SHA3-224" with linespoint, \
  "chain_speed_80_sha3_256.dat" using 1:2 title "SHA3-256" with linespoint
