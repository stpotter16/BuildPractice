# Just bootstrap the build

export PKGPATH=/work/00161/karl/stampede2/public/grvy-gnu7-0.34

gcc -I$PKGPATH/include -o main main.c -L$PKGPATH/lib -lgrvy -Wl,-rpath=$PKGPATH/lib/ -l:libgrvy-0.34.so
