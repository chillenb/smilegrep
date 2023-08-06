# Maintainer: Christopher Hillenbrand <chillenbrand15@gmail.com>
_pkgname=smilegrep
pkgname=smilegrep-git
pkgver=0.0.1
pkgrel=1
pkgdesc="lightweight greplike tool for cheminformatics"
arch=('i686' 'x86_64')
url="https://github.com/chillenb/smilegrep"
license=('custom')
depends=()
makedepends=('meson' 'cxxopts')
optdepends=()
source=("git+https://github.com/chillenb/${_pkgname}.git")
sha256sums=('SKIP')
build() {
  meson setup --prefix=/usr --buildtype=plain "$srcdir/$_pkgname" "_build"
  meson compile -C "_build"
}
check() {
  meson test -C "_build" --print-errorlogs
}
package() {
  meson install -C "_build" --skip-subprojects --destdir "$pkgdir"
}
