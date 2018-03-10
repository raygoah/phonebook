reset
set ylabel 'time(sec)'
set style fill solid
set title 'performance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.15]'output_all.txt' using 2:xtic(1) with histogram title 'BKDRHash', \
'' using 3:xtic(1) with histogram title 'APHash'  , \
'' using 4:xtic(1) with histogram title 'DJBHash' , \
'' using 5:xtic(1) with histogram title 'SDBMHash' , \
'' using 6:xtic(1) with histogram title 'ELFHash' lt -1, \
'' using ($0):(0.084):2 with labels title ' ' textcolor lt 1, \
'' using ($0):(0.079):3 with labels title ' ' textcolor lt 2, \
'' using ($0):(0.074):4 with labels title ' ' textcolor lt 3,\
'' using ($0):(0.069):5 with labels title ' ' textcolor lt 4,\
'' using ($0):(0.064):6 with labels title ' ' textcolor lt -1