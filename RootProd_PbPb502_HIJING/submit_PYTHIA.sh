prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS mc15_5TeV.420000.Hijing_PbPb_5p02TeV_MinBias_Flow_JJFV6.recon.AOD.e4962_s3004_s2921_r8639  \
    --outDS=user.mizhou.mc15_HIJING.MB.Mar16.pico \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS group.phys-hi:group.phys-hi.mc15_5TeV.420000.Hijing_PbPb_5p02TeV_MinBias_Flow_JJFV6.tid09732007mis_r8638_v7_EXT0/  \
    --outDS=user.mizhou.mc15_HIJING.UCC1.Mar16.pico \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS group.phys-hi:group.phys-hi.mc15_5TeV.420000.Hijing_PbPb_5p02TeV_MinBias_Flow_JJFV6_tid09732013mis_r8638_v7_EXT0/  \
    --outDS=user.mizhou.mc15_HIJING.UCC2.Mar16.pico \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS group.phys-hi:group.phys-hi.mc15_5TeV.420000.Hijing_PbPb_5p02TeV_MinBias_Flow_JJFV6_tid09738730mis_r8638_v7_EXT0/  \
    --outDS=user.mizhou.mc15_HIJING.UCC3.Mar16.pico \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

