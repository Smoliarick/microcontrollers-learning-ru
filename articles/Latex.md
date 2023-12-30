# LaTeX файлы и их редактирование

Чтобы использовать файлы формата `.tex` в VS Code нужно выполнить следующие шаги:

1. Скачать и установить [TeX Live](https://www.tug.org/texlive/) - для Windows
2. Скачать и установить [VS Code](https://code.visualstudio.com/)
3. Установить расширение [LaTeX Workshop](https://marketplace.visualstudio.com/items?itemName=James-Yu.latex-workshop&ssr=false#review-details)
4. Настроить расширение: `Shift + Ctrl + P` -> `Open User Settings: JSON` и добавить следующие строки в конец файлы:

```json
"latex-workshop.latex.tools": [
 {
  "name": "latexmk",
  "command": "latexmk",
  "args": [
   "-synctex=1",
   "-interaction=nonstopmode",
   "-file-line-error",
   "-pdf",
   "-outdir=%OUTDIR%",
   "%DOC%"
  ],
  "env": {}
 },
 {
  "name": "xelatex",
  "command": "xelatex",
  "args": [
   "-synctex=1",
   "-interaction=nonstopmode",
   "-file-line-error",
   "%DOC%"
  ],
  "env": {}
 },
 {
  "name": "pdflatex",
  "command": "pdflatex",
  "args": [
   "-synctex=1",
   "-interaction=nonstopmode",
   "-file-line-error",
   "%DOC%"
  ],
  "env": {}
 },
 {
  "name": "bibtex",
  "command": "bibtex",
  "args": [
   "%DOCFILE%"
  ],
  "env": {}
 }
],
"latex-workshop.latex.recipes": [
 {
  "name": "pdfLaTeX",
  "tools": [
   "pdflatex"
  ]
 },
 {
  "name": "latexmk 🔃",
  "tools": [
   "latexmk"
  ]
 },
 {
  "name": "xelatex",
  "tools": [
   "xelatex"
  ]
 },
 {
  "name": "pdflatex ➞ bibtex ➞ pdflatex`×2",
  "tools": [
   "pdflatex",
   "bibtex",
   "pdflatex",
   "pdflatex"
  ]
 },
 {
 "name": "xelatex ➞ bibtex ➞ xelatex`×2",
 "tools": [
   "xelatex",
   "bibtex",
   "xelatex",
   "xelatex"
  ]
 }
]
```

5. Далее можно создать файл формата, например, `test.tex`:

```tex
\documentclass{article}

\begin{document}
This is a \TeX file.
\end{document}
```

6. Скомпилировать файл с помощью клавиш `Ctrl + Alt + B` (появятся следующие файлы: `test.aux`, `test.log`, `test.pdf`, `test.synctex.gz`)
7. Для открытия файла формата `.pdf` в реальном времени, используйте клавиши `Ctrl + Alt + V`
8. Сочетание клавиш можно заменить использованием кнопок в правом верхнем углу экрана