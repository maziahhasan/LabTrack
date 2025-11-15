# Run CCCC analysis on the project and save report
# Usage: .\run_cccc.ps1 -SourceDir 'c:\path\to\labtrack' -OutDir 'c:\path\to\labtrack\docs\cccc'
param(
    [string]$SourceDir = "$(Split-Path -Parent $MyInvocation.MyCommand.Definition)",
    [string]$OutDir = "$(Split-Path -Parent $MyInvocation.MyCommand.Definition)\..\docs\cccc"
)
if (-not (Get-Command cccc -ErrorAction SilentlyContinue)) {
    Write-Host "cccc not found in PATH. Install CCCC and make sure cccc.exe is in PATH."
    Write-Host "See https://cccc.sourceforge.net/ for installation."
    exit 1
}

if (-not (Test-Path $OutDir)) { New-Item -ItemType Directory -Path $OutDir -Force | Out-Null }

# run cccc
Write-Host "Running CCCC on $SourceDir -> $OutDir"
cccc -j -x *.h -o $OutDir $SourceDir 2>&1 | Tee-Object -FilePath (Join-Path $OutDir "cccc.log")
Write-Host "CCCC output saved to $OutDir"
