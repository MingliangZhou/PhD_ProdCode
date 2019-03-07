prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_hi.00287281.physics_MinBias.merge.AOD.f657_m1533\
    --outDS=user.mizhou.data15_hi.00287281.Jan19.ver00 \
    --outputs=myaod.root \
    --useRootCore
