# maciejmatczak_keyboards

Repository to keep my QMK keyboards.

If you have your own keebs and don't want to push to QMK origin, this setup might be for you.

- `qmk_firmware` as a submodule in this repository: pull it whenever you need, checkout the tag you want, rollback to any tag you want - no any rebase ever needed
  - module uses `ignore = dirty` to not throw warnings about symbolic links
- keyboards setup that replicates the hierarchy in qmk
- `Makefile` with targets symbolic linking the keyboards

## Five by six

[Repository](https://github.com/maciejmatczak/five-by-six)

```shell
cd qmk_firmware

make five_by_six:default

make five_by_six:default:avrdude-split-left
make five_by_six:default:avrdude-split-right

make five_by_six:default_colemak:avrdude-split-left
make five_by_six:default_colemak:avrdude-split-right

make more_organic:default:avrdude-split-left
make more_organic:default:avrdude-split-right
```
