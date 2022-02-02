# Trying out `pybind11_protobuf`


Needs protobuf, pybind11 installed, then run

```
cmake -S. -B build
cmake --build build
cd build
python -c 'import fastproto; print(fastproto.get_person())'
```


CAVEAT: currently this doesn't compile...
