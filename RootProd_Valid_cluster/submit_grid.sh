prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_hi.00286711.physics_MinBias.merge.AOD.f655_m1533 \
    --outDS=user.mizhou.data15_5TeV.00286711.Dec07.ver02 \
    --outputs=myaod.root \
    --useRootCore 
