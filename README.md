- [x]   works but not good: too much column:
    -     --> just verify the number of elements in the word array
- [x]   `SIGSEV` if one or more column is not separated with (`':'`)
- [x]   `SIGSEV` if one or more empty line is added at the end of the file:
    -     --> bytes read == 0 ?
- [ ]   the first column must match the len of the ship:
    -     --> when calculating ship_len (create_map)
- [x]   remove all lib files and functions unused in the project
- [x]   WTF is `line_checker` in `file_validity.c`

- **Bytes Communication**: see in the byte communicating enum and defs in `navy.h`.
- **TODO**: put @todo in the doc to add to doxygen todolist.
- **Building Doxygen**: `doxygen doxygen.cfg` at the root of the repo build the doc in `./doc` open `./doc/html/index.html` to view it.
