# jupyter_fp_ikf_v4
Jupyter notebook to analyse the recorded data in the student lab course of the institute of nuclear physics of the Goethe University in Frankfurt.

The provided notebook gives a general structure to plot and analyse the data recorded in the 3rd part of the experiment on statistics and fluctuations. In this part the voltage dependent dead time of a multi channel analyser is measured with a double pulse generator. The delay between the two pulses can be regulated, and observed in a oscilloscope. The number of counts in the MCA is recorded as a function of the delay.

The code to analyse the data and visualise the results is written in python using the `numpy`, `scipy`, and `matplotlib` modules.

To have as little as possible requirements to the students the notebook can be run via mybinder.org:

[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/hscheid/jupyter_fp_ikf_v4/main?labpath=Analysis_part3_py.ipynb)

###Todo:
* Write some more introduction
* Update the analog manual (pdf)
* Include parts 1 and 2 of the experiment in the notebook, or add specific notebooks for them
