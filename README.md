# smilegrep
lightweight greplike tool for cheminformatics

## Installation

```
meson subprojects download
meson setup build --prefix="$HOME/.local"
meson compile -C build
meson install -C build --skip-subprojects
```
