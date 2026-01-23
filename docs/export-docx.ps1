# Requires: Pandoc installed and on PATH (https://pandoc.org/installing.html)
# Usage: In repo root, run:  powershell -ExecutionPolicy Bypass -File docs/export-docx.ps1

$ErrorActionPreference = 'Stop'

$items = @(
    @{ Md = 'docs/exam_basic_templates.md';    Docx = 'docs/Exam-Basic-Templates.docx' },
    @{ Md = 'docs/exam_advanced_templates.md'; Docx = 'docs/Exam-Advanced-Templates.docx' },
    @{ Md = 'docs/selenium_pytest_cheatsheet.md'; Docx = 'docs/Selenium-Pytest-Cheatsheet.docx' }
)

foreach ($it in $items) {
    Write-Host "Exporting $($it.Md) -> $($it.Docx)"
    pandoc $it.Md -o $it.Docx --from gfm --toc --metadata title="$(Split-Path $it.Docx -LeafBase)"
}

Write-Host "Done. DOCX files written to docs/."