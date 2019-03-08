prun --exec "sh myrun.sh 10 250 %RNDM:1 12"  \
    --excludeFile .svn,make_submit.sh,Ampt-v1.25t3-v2.25t3-Aug4,ampt.root,submit_AMPT.sh \
    --extFile ampt-v1.25t3-v2.25t3.tgz  \
    --outDS=user.mizhou.AMPT.May23.Bimp12.250.test1 \
    --outputs=ampt.root \
    --nJobs=20 \
echo "250 : $? " >>Log.txt
echo
echo



