# Quality Report and CK Metrics

This document explains how to run the CCCC (C and C++ Code Counter) toolkit on the `LabTrack` project and retrieve CK metrics and other code quality measures.

## Install CCCC
- Windows: Download CCCC Windows binary or use Cygwin. Add `cccc.exe` to your PATH.
- Linux/macOS: Use your package manager or build from source: https://cccc.sourceforge.net/

## Run CCCC
Open a PowerShell terminal and run the helper script:

```powershell
# run from repository root
.\tools\run_cccc.ps1 -SourceDir 'c:\Users\SMZ\Documents\labtrack' -OutDir 'c:\Users\SMZ\Documents\labtrack\docs\cccc'
```

The tool generates an HTML report in `docs/cccc` with per-file metrics and a project summary.

## CK Metrics
CCCC reports metrics like:
- WMC (Weighted Methods per Class) - complexity per class
- DIT (Depth of Inheritance) - tree depth
- NOC (Number of Children) - immediate subclasses count
- CBO (Coupling Between Objects) - coupling between classes
- LCOM (Lack of Cohesion) - cohesion metric
- RFC (Response for a Class)

Open the HTML report and collect the metrics for each class. You can include the metrics snapshot in this file to submit with your project.

## Notes
- CCCC is a third-party tool; make sure to verify environment-specific variations.
- If you require a CSV/text report, check the `cccc` commandline options to export machine-friendly format.

