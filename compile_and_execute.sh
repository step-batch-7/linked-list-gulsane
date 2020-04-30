mkdir -p bin
directory=$1
executable=$2

echo "compiling..."
gcc -c ${directory}/*.c
gcc -o ${executable} ./*.o
echo "commpiling done..."

mv ${executable} ./bin
./bin/${executable}
rm -rf *.o