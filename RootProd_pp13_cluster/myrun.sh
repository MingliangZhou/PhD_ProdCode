#if [ -e MyAnalysis ];then
#    echo "MyAnalysis exits"
#    rm -r MyAnalysis
#fi

#tar xf myanalysis.tar.gz

#rc find_packages
#rc compile
echo "Starting the run" 
cat input.txt | sed s/,/\\n/g > input2.txt;
echo "List is made"

#cp input2.txt  checkTrack/util/

#cd checkTrack/util/
if [ -e Output ];then
    echo "Output exits"
    rm -r Output
fi

#testRun prod.root  Output
#runpp  -n 2000  input2.txt  Output -f
runpp   input2.txt  Output -f

#mv myaod.root ../..
#cd ../..
