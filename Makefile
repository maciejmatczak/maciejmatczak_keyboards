.PHONY: link unlink

link:
	ln -s ../../keyboards/five_by_six qmk_firmware/keyboards/five_by_six
	ln -s ../../keyboards/more_organic qmk_firmware/keyboards/more_organic

unlink:
	unlink qmk_firmware/keyboards/five_by_six
	unlink qmk_firmware/keyboards/more_organic


.PHONY: git-submodule
git-submodule:
	git submodule sync --recursive
	git submodule update --init --recursive --progress


.PHONY: qmk-update qmk-set
qmk-update: unlink
	cd qmk_firmware &&\
		git checkout master &&\
		git pull &&\
		git tag --sort=committerdate | grep -E '^[0-9]' | tail -10
	$(MAKE) link

qmk-set: unlink
	cd qmk_firmware &&\
		git checkout $(tag)
	git add qmk_firmware
	git commit qmk_firmware -m "Bumping qmk to $(tag)"
	$(MAKE) link
