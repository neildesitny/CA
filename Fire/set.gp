set term x11 size 800,600
set size ratio 1
set palette model RGB defined(0 'black',0.99 'black',1 'green',1.99 'green',2 'red',2.99 'red')
set cbrange[0:2.99]
set cbtics("Empty" 0, "Tree" 1,"Burning" 2) offset 0,2
set title"My Cellular Automaton"
set key at graph 1,1 bottom right reverse

#set xtics out -200,10,200
#set ytics out -200,10,200
#set x2tics -200.5,1,200.5 format ""
#set y2tics -200.5,1,200.5 format ""
set xrange[0:]
set yrange[0:]
set grid noxtics noytics x2tics y2tics front linetype -1
