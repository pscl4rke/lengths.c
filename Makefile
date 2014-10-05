

# FIXME: Could really do with a test suite
# FIXME: Need a licence
# FIXME: Should add a README


DEFAULT: lengths


# --- BUILDING ---


lengths: lengths.c
	gcc -o $@ $^


# --- HACKING ---


indented:
	indent -kr -brf -nut -TFILE *.c


