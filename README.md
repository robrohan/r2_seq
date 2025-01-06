# PL_SYNTH

Create raw samples for sound effects and music in JS and C/C++. The synthesizer is a port of [Sonant](https://www.pouet.net/prod.php?which=53615), the tracker is written from scratch.


## Release Version

pl_synth is implemented in multiple different ways. The release files are self-contained, i.e. you only need to use one of these files in your project.

- `release/pl_synth.min.js` - the minified version of the vanilla JS implementation. 1.2kb gzipped.
- `release/pl_synth_wasm.min.js` - the minified version of the JS+WASM implementation. The compiled WASM is embedded. 2.5kb gzipped, but about twice as fast as vanilla JS. Recommended if you're not size-restricted.
- `c/pl_synth.h` - a single header library for C/C++



## Tracker software

Songs and sound effects can be created with the tracker software contained in `tracker.html`. After cloning this repo, the tracker can be launched with a simple doubleclick (i.e. it loads fine from a `file://` url). The only requirement for the tracker is `release/pl_synth_wasm.min.js`.

An online version can be found at
https://phoboslab.org/synth/


## Demo Songs

* [Drop](https://phoboslab.org/synth/#eJytk9mNwCAMRBuaD8xhoBaU/tvYGSCH9pKyWpDBNiaYZzJaboYxRgWbRYNhqt2Q6AhBzohSLMEocFjnkkIdHKAtsR8YnHAKTo3+YanBcsGcS8B72287t7e2Ukvl4an4m5227W/t4xCGhbgLixPwqUcdwyPYYG6FahbT3iJaF+TCoVYhTXCRvujScfWLNGUfHDC/dbUJhrIJreUTD2Xn/XXbt8vSKNpPVIrL+9aaywxTKlkH0r0jPgcmkdBAM0puWoLDDQ91vkgkT8KSCaDQloZY5xNcHbC7LzDPK6wjC/7Xu/JuK1mlOQseTWWLFpjqdHvTT+UBmTUPs/p0IvEu8Pk/ZXj47TILYbjK85N6qH0A4LHEdA==) by [no-fate.net](http://no-fate.net)
* [Q1k3](https://phoboslab.org/synth/#eJxtkVuWxCAIRDdUHzwEdS2e7H8bA5g40+nBIwI+uKksJ25Ya3UADDED/oRgIkBdPfIGAfOcFTZ0vrAY3wN1/4w4tVgcOXH7Yx8b15Vnaz+7CyLk8STJEgYLGn2SwoFElFAD0uIJZAmKdq/2zrNNwquUV7yMZeSGWHnaXCkLRo8XRp3xeCnh4k2eWpCBxS6w+OpAG9mNJ5UahOmF9lLnKNQmcmL74z5rm6T6+y1QEDSNziVCN7IMUg/Kn+Q8CIMj4lnX4gorH5KHJmW516JRObtbHta+Ffuq0/91sV817Ur7AYzBfQA=) by [no-fate.net](http://no-fate.net)
* [Underrun](https://phoboslab.org/synth/#eJyNU1mWwyAMu5A+4o3lLLzc/xojmzbtdNo3JcEEb8jCWRFiWGt1cGgEFAOQsTfGRY7uiGbNIEcOyJx0mz4wFR3tQJkYxp3YgJ1YSiXj8OXKiMUpqngZopIG8ZLzo/nVcDlIP89MXyXK3AdyRCoStwQn62u0CgHFMBYYTjdmB9WermmOqgwf33sZJkx9iVwshZe4w9FkTGYDCkkxvhGh0CQERROtL+57psbbJzOKH1fRnz6fqOg9z8zLHoWApYZ1S42HB5FmSzCa52uxludXn8Dr3v5ZvyPjrUO7HGw7bNyxeTrujFFKJ/pm7DohaC/6CNVCC7uDzVoR6d38VsEb9i6SrP9pIbu10KjQofsv2e0X+8bmMcmUZfmhVLTssgSO9SvVQ+wr4+mPeeb4AQ37t8M=)  by [no-fate.net](http://no-fate.net)
* [Voidcall](https://phoboslab.org/synth/#eJytVFmSxCAIvRAfsoh6llTuf43hoVl60l0zH52UBAEJ8MDNnStt29YoHu6FKLgRLDsEo1HvxMXZyCrERSpJjUVsTkrWdtqYXt6QbBzmnEdqyRVEc12S/Odh99ZQsPYdDg3WIop/wprE4IJLnCqjDGJRI3ZBaBGmpYFTnalFXr2En7mR9DK/QpdMMnQc+RpBeSIo+hpJhyjst0g6BOb/Ie0NeThMwFZLocAdDLAuqHZAFg9VV9djw2OESoKTamEvFi4mSrrQqvTXXhM9Yfr1hAg5flb4U+GpGE/FgEL1oVC+25wViL5C6osVfM0iWOvUWxMaCJ9LdLqYhpnKsiVvZ7u+vjdZJqw2A7BF5q6ewje6G0IYZgVCk2XKgSxqLQxbcRpWelQYVsCH40IAPgt9ws2gK9KzAseAzfg0S9ZBjT+Uz/Ri+R5etAglPjzgdMagEVxrnjLDrRDNIGBZ6vLC/imoNfVrf0582uTQejmGNmVz7uyYuylrp+w4e/uTt4udOIRp5uQTO4+rq18sR1/EzYfUvGM0KuJcd61F+tEVlZxxILblV2NcGZ5NAZTP5n3HsuFe3fcfSjkwMg==) by [no-fate.net](http://no-fate.net)
* [Liver](https://phoboslab.org/synth/#eJy9VFuS4zAIvFB/CNDzLK7c/xrbgOLYmUpVdj7GiWQESKbbjY/WxHAcxwAvWQoDTf61CG2MuSBqFWLdOjMEijZtQVsFHSo+V+4IY7UHDs/xtfrg+hDmYk8MRfrzeo+1LKV1P+gX+9bj4Y+MlbbGIibdk6Vk8bC1BhrRGKT4tdOM6N2a6AsNPSBV8FzbmC4jUFnxgFo+cWZd+9YLWkGVhdrLIH3FKyhm3K4MQDofIsXTeZ+DRwQAiB92gvVbmpf56viY8eJBAhcuptcmXt90+D5YsBNRA+r5C5gv1j+aPzinufL1kHGtzn8ZjrcLXbVQW7p6Ek7ZyHDhmdfHJK0nGX8goaDro4S8J1zZASdsvsvhnJG9LrKda1Jni3nqeEZoxyikUznmY6sGyKlqWufq7sbXqSlDICdraZ2ruxtfp/qxYcYUPHnKc3V34+vUN7FYtkzoUpTUksmZXZrhWtiL/g2qMPN+rsmuzpDJqyvt2Tm63+22z9WnWJ6TQqgXdV+2PWP3yP/tvbTK/WPhOKUWY+ZSfhjErIqLbMJbhFKjU0Og9JSRoJts/O/t+vDrH/UpKmA=) by m / Bits'n'Bites
* [Regressions](https://phoboslab.org/synth/#eJyFVdexxDAIbIgPEZRq8Vz/bbwFLKcLz55DSAJZu4TbamGmbds64RFuxAQVayRaMaE+JrGoEZtUqGYkNIpAhbVC4kdcKrx8Wgfxi7Y4Dq+vrfG6ZngrNfLTqs/hs+ETbpNDSBesZc0O7bcRzmLc3vdjCOkCQNbs0N6N4ijV86iRVmNJFyxtzQ7tl5GqHyUheYTeXi9H7dQzScXnLyrVAjIL2ShQxHlq0KTazm4Qeb56mx960hrRdX76c/i+tz7z5VnejsQskYzc2odWHIPxJGulB62eKKq4nGCDkD9gu7g5xpFf/IDhgY3fsbk84JxL97Wfpk/LD+gPqr4dvtjoZ1wjlpqMRFgZTIiQoYyaIjFy30qDe/dysOr1ZVlNs13usXDTNy5ul+TqZ6Bin7ePtfdLil+Sx5owd9JSBO2gFrgOuKHkp9evZB7CoUc5mzjsiJjS/2MMq/4ziMxnWbDt5Rtl7bS2OD9mM3Bx7XtdMujiqBS74MlrJrQSnYdLVhNr0xZNCm1n6AwcWADOtgfUlVkfvH9CQtfZkYspajmEHOIakNV60kUOv+nA0tKWY+6ca/0WWExaW2ENrQebLdvkZeDGy86vdq6na1isTWhJaLRG/DOYF2moBaqg/8OsSkMMBtLGq1upT29UVsBh9wiLSjIqym8VlczJ/pcQv7cs/qFmt7j1sGc7+1CxCcpiaahfmVbLRUagMKf1QTobA4R0lGVWqBZYM5IJ+dYLUp+5BoKOIo3w36F5clD26Iu84Ns9QPbLnz/gnn0d) by m / Bits'n'Bites
* [Beatnic](https://phoboslab.org/synth/#eJydVmua5CAIvBA/xLdnydf3v8ZSgMak0z0zu9lWBB9YFDhHCb3TcRyNiJhiKUSbSBwCURktEDfRUZFxLFnsiSlT5BcdjNnEdPbJ+7gk6DCGJut3zpj2InsdnHE8/amDDzZ4+qemS3PO/213No/rt6PM9nrhLlV1IwqCRN1FioAwoOk5BlMyh1gAucP5+ftqvHyKZirLtxROcdear93G3rEEv8C3JnFvVZqKLUMbhUYiXIhDt763rxwwzYz5bNnZMGdk/5QDtxBcwX+L0FtsPhGBOKb12we65r+O3IXJiofmXfjYfNy6DMIPsRkWsjbpFZGyDTjqQHiUinMspyzEgl7w5hQ1rWWn2BCENsAowSBlYMCGEppognfoedm8SRaqC7xwNO4x4Bw2Z3G4OpunTFJ91NFWQnFd4ixEYKpU5QJUM04DEYdt/DU1lFUmJfU0byuswszob2kbPSkebNz1UmkRSOdJ86MuuM4Sz7ZO5dxtP4Qvx2rYdWm5Dq4En5wENRrv+7lBlGDLpxVPNBpTpjQqSwnoWdDpIdbqhjqqBkq9AcixeICKVR1nkZX6ImGcPTTNInM1NBSesYYcNE7MhpUj5nmgUpxS6ku6YWpeGN7AwX9Xc9MjWifG9Vq/mWtVs+xesfoeNSjzWA6UG8QbvOtRTbg0Z5A+Iz2F6ZIBAFbUYQDwhKwwGpEhHVcEef6f3aa5jO+5+QTMQ/TxOqF067vPxdOShz79PQ19+wWpCNesQkEY5eQYX0LfJLCajH0pkPv+6p/zxgz69jSh2nFpLm2+IyFKJue2cOBcEua6GrcFqhbNtGupHud+Yy3N7we18yD1beb43b2V+/XRyR/W2iIj8fMF55z7HV3/9Zqaow839aKUHu/7kTvOdi7RKgmO1PyRmPb051N/sR3+oHq9/gHG1hXB) by m / Bits'n'Bites
* [Frank 4k](https://phoboslab.org/synth/#eJzFV2ly6yAMvpB+ILHYnCXT+1/j6ZNEjImTJm86E1JsWaAFrfRWue10u9020sFdSEjBPuDcad+J616I01ZJcqVM3DgpshlIupRZCQAwE//QDV/yMIkqgaacsPi+mhib8rqxyvziVBU4qw2+N92godGfQMHRJfwJ9FTHMd7X4aB4lMEb//wgKBCvGj1VGU4gla5xqbGZGheSlDS+Gp5Vv0gKZIpHqsYiazSy/TaNOBMUWB0ybSmO1AgWC8ji2fLJy057Paa9vvH+/EhK0BP9F/np8RH5SfByjF9pZyO8MNHYsbiew2mS9A0EXI8pTSuSSIdru4JcUFFEi4ok93IrLm7UouxCKtGMmFYBZohf1H8KxnF+2bra/XcSS58Lc7+wGz1Ex9uGPnoCbGeW4BRWzi1rdnSYqO7aKQAqQuxpsmA1ydYSrhrCdZOgpy0hR+I2y0LJd42PSnPGQq60A7Ef22asbcszJ9MaqEC8XFboEDSE4NNQgXi5rFDoMOm/ugWrOYX/xT2qdY2rWr61tThaPggShCM5lLFoEy9U1W8ZbkzwZO+6rZedOtzcEtkSWVWEcvkD57mTwkaBa+BKfuoejgNLLuPIrjwM0vodknFsX8XFwgxQndYNmIfhvUNMpuOCjXo2pXSjhO/jpefUEC7cqbSkB92hLKec9a01ouBio3ZGYcF7j6SRaBgMHn7WPP1a/GZ4+tnp4a7vzVeFYtp5QWLoY+cKBvBahHtme4fjqvuq0Qn/uGt6vLfV+F5kTx2wZkjtW7L78F40AR2dW92o1yh52pHsKqyR2utkiBE1SJF5jhHf99sFEjusgVSso1tUOdlqrJc++q0RIltOtHfEIA8EgP6USVmZlJXJUFJ4YnI2ol+s/HrGsmlXtj/uOZZLamq3zf6PKLim7cUt2NsSSaMXr2+6ws4XNVO2odg2sTPWA71Bda87M7oNkiV4UZe4QcPGzg/jHzUrmFY=) by m / Bits'n'Bites
* [Synth 4k](https://phoboslab.org/synth/#eJy1VVu26yAInRAfguJjLFmd/zQubDQxuT09H2c1reWlhm5we2hNlY7jGGQPVyYyrZjaxR0pmcYdP0w83ClaqFqoUyZfYGIUkhcdTEKfhn2zbc5Tqm3TqJPa0oOL7317uKRTzd33z/qcc03QbZ4vNPV0rznu9vfMCXpF3m5/LXj3EslYk6DDw8Ni/MxMDCwur5f/yx6+KXy+IUy55gpwmTog12oQCVDyl9BHVH8YANUTjqxP9Q++hdGfd9xdAUwNPAAB8LH+k2jAokVJmjTEs6nm7N48NdlPrw6PBVMFVG5Fh/0iF0AYpW1JTeM7wdmfGCqzFTfjK0GcTmtNjJKjTXfjl2CPoWkdq8v4EGxR24ai9GagK6E5nWhko5eorqA0w53Vq8+avcg8239UyrPCq8rR6p/lvc5IVnGoQ6bL9704ap4DT1XIm3EF09TblNNeGC99xaCnN3HZ43FuLwaaTN6gtmQg9SCikYaDX7xSag4pfsKUnenrhv2F/3+fk3ZuhHm398DeIkOQCvmJ7p6EMJWUPBHjgIL0BjVvpBa90z1zA8tupDFpoFUkcU/1fvE8pc6kUSa5+NzL9LwR+hPMjc5LDyoHY+UAMzuVZ2Qr3v+cJVICITwSXckyWCpk8Rc94DvNc/1+mVX5MQZTefOftP7y5x/Ke5Wt) by m / Bits'n'Bites
* [Chippy](https://phoboslab.org/synth/#eJyVVEmSwzAI/BAHsWh7iyv//8Y0ix07s1SNEiQiI6u7gRxm3Og4jkkYokZMg2jD5w2fWCdJa41sMJP0TkZ7Ca2NOOmYJo4ydrnLiw6m/Mh7xu7BoojKaVzTqsnHXxH+XtxFNZ3HWFtN+YLfI14vB5EcQQHwgyN3C457Ol0l7YC7DDvc8KJky22RUh/fyQUx7XG5Bg22AuNuXMe95RLi6LxFsck7eFdULnYDzNuvczKcP5Rk01rUbSEUcCWo3iEjjxPPRoifeOMcVr0l5IbUpcDkogxXfnrUFTH53O/7jLV5puXGwe9EZIQ7qKl3JgyJaWa44FbDGVTRWENpAxGHjggZUIhBEQTEHDb3kBwEVUL4yFt9kxDw/CDaPn0CPDVUFdbc8TL2VDzqWGnsYP6ZZ+gVhnyHyUgD4DApc+RuqmnW0/59vswcpJTUYSiisL9PvG+C0GH/Pl9m5pbierahCKMAym1wBQWJOh+KPPLiKEtP4/bkhcLTUJaeu/h/QaaruqqjKoGPzrmAPxuq3I9cR1nZ6ZNGSWnfA50yp1TGtYmcLQJYADsC0fLNq96jVx6I3sNbE6nIdn0+GJcblR89kF2PXvLxBa4EFJg=) by m / Bits'n'Bites
* [Fabrik](https://phoboslab.org/synth/#eJytVG2SwyAIvRA/REHxLE7uf43lEZttTNPuztQmo8gDHh/paNaUxhicyFdlIs7UCJvihqTllskq+bWlRFkSGRWhstFgwi/HWxxLU2qkrh1cMlxw6fvWYpPTpcgJAru3wHkp9QSBGfYcwvl0Cv4SoV90kr/gRMSd/LMQE9m3DZUPKat6V4zwNIkGRTMl9dRJaqkFFt6xnIVqw2HW4Ogpx/skR19zTMvz8isQZpsiW4j1gnNFMAwgdw/p9GLgGs4kxsZkQVH9aK4QhC8+fFKoBpD3+Qx2lhbOeNSBeNvku5N7xengvCYDsCfK6sG0zuxQL1b0h9XjLc7C1+zMyV30NPKGgTvswRF5G2qpKQqAEqi4PrbHKpFfeEKLCF0VtzUCq7GyX4ILSjDnYw7KX6WL4a3V7/He7IPvD9I7fD2+g/l5zP+RhcRupn11cVHf5fBQvq0Z1g+IaAxv) by wullon / adinpsz
* [Microscope](https://phoboslab.org/synth/#eJzFV1mS6zAIvJA+rN0+iyv3v8bQIGRttmfevKqxS4Eg0NI0UnJGm3Zznudu6LGHM87sJpPuNms8mbbN2EjNJ5/oM5ODtZsLxsVgyOIsPgOFsHLEjzktnKh5E0wkaysxtjy7Ochit0tRn8mQadDT+kiThM3IdPrYwFNKZ2Nn36tnEdb5xiziQEjwnRN/BwrqJq6BXbHzOjnFc58YYhcgQbGJjU5XBk0CJRGYq4mCVeZPJfBpY7JrP+8xuHZzxVm3R50fwMwhDvaowDjhgdvoMenYDtLtjgQfMJNvMplXbCm/MktDAZGxSnKmFENby1Q91V4jmQd9lrF0TlqPWQWi3W7Jqeatz8y2NKv3ulNi4mguUNai8qWoqIoAJmrJAzwC0u92t4QZcGrragPzoXNdOSZMGb6DNUiaGFR86+VevdReoxhKoWuLAm80TjvKS4SFh5N3YbdkZZrhMSYKcgwWQwdGZflimYiElwmRMGcNvPTm8OChAGctIVKAo+2GvQJ3+4xk1Rb12OFG2Z/0la3qGczk4uXGp+igr2x9fwGLW8pm0le2qmeAxPXNDfZRZ1ka/EddCPHPGOheio3OuUlf2fr+/4KBkxbDrK9sff+vMIh8LZBsue1QAYXmIZFEcbnsMnPX4bAtjHaWGWz5BUn7FwdA5FNVZd8/R+ib62k6XZy5k6rdHIOLk0Ldr0F6sep7CV0s9OoobR0/TV+HatvDAr43wE34wm0Ku24L/CwSEcEIviggM7K/2euYc7gWfWqoAdJ0L7jRv33/FBCVQljOfZbGL5dJVqOgjRnrOprO18CeXKPjStERWvdr1AUl+4+7xd14jXle5dMH5JELnOSOC8a7et17XM/l0sLNxkwy1ztmai5qtUui0+SvFIha9OsiWH55sd6OUMrhtgzeC2RtnKf/1kw/N966NfP9UfsVtk/BrxBd7JZfaMpwXLex/Fvkfwp2x89Pex1aAbQ93OI6C81lhlJINKjK3mOOUHnoqdUdCPPpcf/MKA1D3ao/cDWvww9rX7h2Hs8reXC9XclTzCs+M1s+ny+2jDSU) by Ferris / Youth Uprising
* [Chill](https://phoboslab.org/synth/#eJytVW1yxCAIvRA/lCC6Z8n0/tco4Ecw0e62U3cwBJDo48mexMhwnmcCGfGFAKJFrPoBgCGo1CnUV4gxYAKkACyxwZaKGWP4glO1lUi2vBQg+aYXsbIXSXrGdIAbMSX91N2IZkx/NZIZw2w8zJjvxi/dFcv2SwVJtgpV86hFtrk8UOOGGjXUOoY3xGgjSXJ44V3sErvxQe9okFKZYokXmFDZGVui+WMGVe7woJY80hYrxDtWL51L9HANiBxsb+HK4/kTWhMwTanYPD121E4mnJZ0nN1r6gqOZLmb8t2T3Cpzd3q++jvjKsTALh1sYedgqOzj4KKKm+X20oy2RWIiBZYdOyeodXTcFNRc6a/fe0kKmZZEnMnlQFo4KD2v6AJWv8JoSfx0LEjsVqwcuxWrxvHmHKXXRGushYhWlX4FECr9WzlkylqBVhOpQ+2xokerSRZjguiq8sO4tZTaDYwuQbd2DB4be8ogU1ho6uUwgsPVHP8loWmMV7eIdlBwKshiTUBl/BWxznYz6nHn3/HoqdR+xyOWdrGVufWCUjapEzhrf3jHZTdq/CrDCNzIlXFZ9k8WX60iVvSdKtdewcbOSzXSxMkD9eK3psxhU4Cn4ZOo0YavE65VGMfwp1euzEzRpP4+sd2i3uJac7/varn//cGWcba1qeZ3gbV7tmzMvZw6vgFeG+hz) by Ferris / Youth Uprising
* [Poseidon demo song](https://phoboslab.org/synth/#eJzFF1uS5CDoQnwoUYlnSfX9r7E8RI2ZTrZnu2o7g6CIIi+dI+Wa4DgOAv7FioCwK5kJNkYhABISoLZxzzwhxoAJMAUoEDfkWRS5AcBALziiTGFhx/PPxxJkhtLxOr70edUjZmxr5ORENhS8T05U0SPtp3ld8p8FYsFGN0FXTZkpN4mYtj7QuTnMO/XddKe2z6RW9n10x5I+kzVIyhOGrMKLMNDrJTYt6pJc2dJGIm7isa2GGmCPe5QICBIEm5yl+ZwCmL+hyPHBvN+a4ep5ZOnJ5vDmF1Mw7dT2ohFCMu2SbszqRNavGrWHJSTN6ECwi6lBo8jiCTmayo/AkxXk52Mu47wGHosKYkzHM/3Ib84pNPBM5walDjxoiYLCRxcgHHimH/kNKA08064R1YEHPQe9HMiRx+nq0b2p7N2O4lac0kBVR5fSe0p3oKt1mjVE++Jbn/Oxncga6br5SEsX6mA455RsY41o4Tt85OGV/2TvW/43PP4Yc5PFZ8sbbSlZNbXsnqhA2iFJFSici3xF8D5cNrh0cNrRPq6JIDmGWqh0Aa0ba+K3hHNId8x2Q4ybISbzVugBoCNWiU8zELzEe+XUsprHFC3c08i8iIVoE6evLTIV+IxmbLJjb7uWMKGlSOtFnLStZnAUS5wuZaY2t3YW4gdr3xt2htTBzL2m95xUKyNnSx5t6SpXT0cVg0ykFnjYCtcIOQyXb7mJ5FhIeiLRT2xjJV7+sn6lj05cXlljb5K5ztJPT5n0LZP8OjXC+4LNqdfmBsaKn6KPhLvIqum8ylD6RJ+OcZl0Xv1ry13N9C5am6RFzW6hguzcRkaOFwkdffAIJIkblAfOnCAoIRTslVA8Oab3aupx9O4xu45P5WiOkzvSt+2Dw7g/Cp6Nc5k4h+bF6xdz/4WJfcaSA2d9fzf7pEl3JUB7gakL7ZlnDVBeSlyV/x20SEiFi7S1evD8YfvMi/dz+Gu14F2i3+T+E+taF/4jvOT3B01yu3A=) by Ferris / Youth Uprising
* [Haumea Drums](https://phoboslab.org/synth/#eJx1UVEWwyAIu1A+BIHWs/h6/2ssYNet3Zt99UURksB0l445pwMQqBhwwkaoOuAN0aNDdtkhvqNjG2pQYwCbgbBrpgSBHJiC+ogmspZt53bH7+MzdhyZGUuFU80XpD7qEf5UQ47gPXy0dsqJuPNfVB/O5/FiXCKGsmIKiawxhHZJyQUryoVFlL5F2tUI0XwamZkdcSshyjsrIZT8WOKab+7CVqCSTX8C5n8ybCwP/vaQU6QF1urpwGp6WoOMNc7Ont0dtCIUulfZfuQv5iWsdj9yvQAzu3WO) by Ferris / Youth Uprising
* [Ambidumbi](https://phoboslab.org/synth/#eJy1VEuShSAMvFAWJhDAs1je/xrTHUDR92Yxi8HSBAKk82kP1c1cjuPYBcPcJQlUzXMiunGINW06J7oVmFKF2po0UYNJzLBbMmQ75aBuj/dagfVQS6IJR5OL+ibrUN2HTWnD9ljJcJxxyu21u/TdtGP3yevrDMcAT7TNyYzASyrpCmffYTJG6Rn7LeOKhEjer0tZ5k5HeIkP0bwGIIdBPw0lIvpi0G7oIbS+OgThX9l/iN0I3qkSnXrErgQY98n9LL5EowrI/htF8tu/ht+JASPSZgktUjM9WolSizzdDG26mG5CLj5/sV3f34Cooo+aRmXZlixbklKAqDZoNXVIKKZ/4HvCu1zfiL6qHcrFkiCJDZ2lIGc8u1S2sqEVjZUYzmXhgFwMYPC5ypRLCTJTcS9Fd4MjlPjgSCZBavRXu4mRb2JoSnEN5WAGAZFr+RUK1oHZHhQRQSw58mpIKRZ2Zli3kVhAGCS/G+pB9khtL28dmDv4DndgpjN8OniXvx4ggP/wEblminOkeu3CZv2PMpMXudq3HfVORsrxL1LSIzUi1p/xv7ha6yEWLnyKlRHn+QMg5yGw) by Gargaj / Ümlaüt Design



## Usage

In a browser, load the `pl_synth_wasm.min.js`, instantiate pl_synth and then
use `synth.sound()` and `synth.song()` to create WebAudio [AudioBuffers](https://developer.mozilla.org/en-US/docs/Web/API/AudioBuffer). These
AudioBuffers can be re-used for multiple [AudioBufferSourceNodes](https://developer.mozilla.org/en-US/docs/Web/API/AudioBufferSourceNode), so you only need to generate them once.

#### `pl_synth_wasm_init(audioContext, callback(synth))`

When using the JS+WASM version, this asynchronously instantiates pl_synth with the given
[AudioContext](https://developer.mozilla.org/en-US/docs/Web/API/AudioContext).

#### `pl_synth_init(audioContext)`

When using the vanilla JS version, this instantiates pl_synth with the given [AudioContext](https://developer.mozilla.org/en-US/docs/Web/API/AudioContext). Returns the synth instance.

#### `synth.sound(instrument, note = 147, row_len = 5513)`

Creates a single sound effect with the given instrument data (as created with the tracker), and an optional note and row_len. The default note value 147 correspondes to a C-5 note. The default row_len correspondes to 120 BPM. Returns a WebAudio AudioBuffer.

#### `synth.song(songData)`

Creates a whole song with the given songData (as created with the tracker). Returns a WebAudio AudioBuffer.

### Synopsis

```html
<script src="pl_synth_wasm.min.js"></script>
<script>
// Create a new WebAudio context
let audioContext = new AudioContext();

// Instantiate the JS+WASM pl_synth. Since we need to compile the the embedded 
// WASM module you need to wait for the callback to use it.
pl_synth_wasm_init(audioContext, (synth) => {

	// Create a sound effect
	buffer = synth.sound([7,3,140,1,232,3,8,,9,1,139,3,,4611,1403,34215,256,4,1316,255,,,,1,,1,7,255]);

	// Create a WebAudio AudioBufferSourceNode and play it
	let source = audioContext.createBufferSource();
	source.buffer = buffer;
	source.connect(audioContext.destination);
	source.start();
});
</script>
```

Also have a look at `example.html`.

### Native C/C++ Version

For usage of the native C/C++ version please refer to the documentation within `c/pl_synth.h` and have a look at
`c/example.c`. This uses `pl_synth.h` to generate some music and saves it as `example.wav`

