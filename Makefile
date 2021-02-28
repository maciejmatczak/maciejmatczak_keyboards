QMK_CORE=qmk_firmware


.PHONY: link unlink

link:
	ln -s keyboards/five_by_six qmk_firmware/keyboards/five_by_six
	ln -s keyboards/more_organic qmk_firmware/keyboards/more_organic

unlink:
	unlink qmk_firmware/keyboards/five_by_six
	unlink qmk_firmware/keyboards/more_organic


.PHONY: git-submodule
git-submodule:
	git submodule sync --recursive
	git submodule update --init --recursive --progress