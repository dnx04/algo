#import "@preview/jumble:0.0.1": *

#let icpc(
  team: none,
  icon: none,
  doc
) = {
  set page(flipped: true, columns: 3, header: context [*#team* #h(1fr) #counter(page).display() #line(length: 100%)], margin: (left: 1cm, right: 1cm, top: 1.5cm, bottom: 1cm))
  set text(size: 9pt)
  set heading(numbering: "1.")
  outline()
  doc
}

#let minify = (code) => {
  // Loại bỏ comment nhiều dòng: /* ... */
  let withoutMulti = code.replace(regex("/\*[\s\S]*?\*/"), "")
  // Loại bỏ comment một dòng: //...
  let withoutSingle = withoutMulti.replace(regex("//[^\n]*"), "")
  // Loại bỏ tất cả khoảng trắng (spaces, tab, newline, ...)
  let minified = withoutSingle.replace(regex("\s+"), "")
  minified
}

#let file(filename, hash: true, description: none) = {
  heading(depth: 2, [#filename.split("/").at(1).split(".").at(0)])
  let content = read(filename)
  description
  if (hash) {
    let hash_value = raw(bytes-to-hex(sha1(minify(content))).slice(0, 8))
    [(#hash_value)]
  }
  line(length: 100%)
  raw(content, block: true, lang: filename.split(".").at(-1))
}