prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS mc16_5p44TeV.420221.Hijing_XeXe_5p44TeV_MinBias_Flow_JJFV6.recon.AOD.e6537_s3282_s3136_r10409  \
    --outDS=user.mizhou.mc16_HIJING.XeXe.MB.Apr06.00 \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS mc16_5p44TeV.420221.Hijing_XeXe_5p44TeV_MinBias_Flow_JJFV6.recon.AOD.e6537_s3283_s3136_r10409  \
    --outDS=user.mizhou.mc16_HIJING.XeXe.MB.Apr06.01 \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS mc16_5p44TeV.420221.Hijing_XeXe_5p44TeV_MinBias_Flow_JJFV6.recon.AOD.e6537_s3284_s3136_r10409  \
    --outDS=user.mizhou.mc16_HIJING.XeXe.MB.Apr06.02 \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS mc16_5p44TeV.420221.Hijing_XeXe_5p44TeV_MinBias_Flow_JJFV6.recon.AOD.e6537_s3285_s3136_r10409  \
    --outDS=user.mizhou.mc16_HIJING.XeXe.MB.Apr06.03 \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS mc16_5p44TeV.420221.Hijing_XeXe_5p44TeV_MinBias_Flow_JJFV6.recon.AOD.e6537_s3286_s3136_r10409  \
    --outDS=user.mizhou.mc16_HIJING.XeXe.MB.Apr06.04 \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

