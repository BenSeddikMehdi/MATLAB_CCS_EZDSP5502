################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
aic3204_loop_linein.obj: ../aic3204_loop_linein.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccs901/ccs/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/MATLAB Drive/ezdsp5502_v1/C55xxCSL/include" --include_path="C:/ti/ccs901/ccs/tools/compiler/c5500_4.4.1/include" --include_path="D:/MATLAB Drive/ezdsp5502_v1/include" --define=c5502 --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccs901/ccs/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/MATLAB Drive/ezdsp5502_v1/C55xxCSL/include" --include_path="C:/ti/ccs901/ccs/tools/compiler/c5500_4.4.1/include" --include_path="D:/MATLAB Drive/ezdsp5502_v1/include" --define=c5502 --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

aic3204_tone_headphone.obj: ../aic3204_tone_headphone.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccs901/ccs/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/MATLAB Drive/ezdsp5502_v1/C55xxCSL/include" --include_path="C:/ti/ccs901/ccs/tools/compiler/c5500_4.4.1/include" --include_path="D:/MATLAB Drive/ezdsp5502_v1/include" --define=c5502 --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


