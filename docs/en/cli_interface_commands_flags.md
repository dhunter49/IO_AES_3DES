# CLI commands

Commands: encrypt, decrypt, keygen, bench, selftest.

**Usage**

```
cli <command> [options]
```

**Global flags**

- `-h, --help`
  Default: off
  Print help and exit.
- `-v, --version`
  Default: off
  Print version and exit.
- `--verbose`
  Default: off
  Print additional information to stderr.
- `-q, --quiet`
  Default: off
  Print only the result and errors.

# encrypt / decrypt

Encrypt or decrypt a file or stdin. Without `--raw`, the output starts with a
header (magic bytes, algorithm, mode, key size, IV) followed by the ciphertext,
so decrypt needs only the key. Padding is always PKCS7.

**Usage**

```
cli encrypt -a <aes|3des> -k <key-file> [options]
cli decrypt -k <key-file> [options]
cli encrypt --raw -a <aes|3des> -m <mode> --iv <hex> -k <key-file> [options]
cli decrypt --raw -a <aes|3des> -m <mode> --iv <hex> -k <key-file> [options]
```

**Flags**

- `-a, --algorithm <aes|3des>`
  Required for encrypt. Required for decrypt if used with `--raw`.
  For decrypt without `--raw` it is read from the header.
- `--impl <soft|aesni|auto>`
  Default: auto
  AES implementation. Auto uses aesni if the CPU supports it, soft otherwise.
  Fails with an error if aesni is requested and not supported.
- `-m, --mode <ecb|cbc|ctr>`
  Default: cbc
  Mode of encryption.
- `-k, --key-file <file>`
  Required unless `--key` is given.
  File containing the key (raw bytes or hex). Recommended.
- `--key <hex>`
  Required unless `--key-file` is given.
  Key as a hex string.
- `--key-size <128|192|256>`
  Default: 128
  AES only. Key size in bits.
- `-i, --input <file>`
  Default: stdin
  File to process. Use `-` for stdin.
- `-o, --output <file>`
  Default: stdout
  Where to save the result. Use `-` for stdout.
  Binary output is not written to a terminal.
- `-f, --force`
  Default: off
  Overwrite the output file.
- `--raw`
  Default: off
  Write and read ciphertext without a header. Requires `--algorithm`,
  `--mode` and `--iv`.
- `--iv <hex>`
  Required with `--raw`.
  Initialization vector. Not allowed without `--raw`: in that case
  a random IV is generated and stored in the header.

# keygen

Generate a random key. 3DES always uses three independent keys
(168 bits of key material).

**Usage**

```
cli keygen -a <aes|3des> [options]
```

**Flags**

- `-a, --algorithm <aes|3des>`
  Required.
- `--key-size <128|192|256>`
  Default: 128
  AES only. Key size in bits.
- `-o, --output <file>`
  Default: stdout (hex)
  Where to save the key.
- `-f, --force`
  Default: off
  Overwrite the output file if it exists.

# bench

Measure performance of the selected algorithms, implementations and modes.

**Usage**

```
cli bench [options]
```

**Flags**

- `-a, --algorithm <list|all>`
  Default: all
  Comma separated.
- `--impl <list|all>`
  Default: all available
  Comma separated.
- `-m, --mode <list|all>`
  Default: cbc
  Comma separated.
- `--sizes <list>`
  Default: 1MB
  Sizes of test data.
- `-n, --iterations <N>`
  Default: 100
  Measured repetitions per test.
- `--warmup <N>`
  Default: 5
  Unmeasured repetitions before measuring.
- `--operation <encrypt|decrypt|both>`
  Default: both
  Which operation to measure.
- `--format <csv|json>`
  Default: csv
  Output format.
- `-o, --output <file>`
  Default: stdout
  Where to save the results.

# Exit codes

- `0` success
- `1` invalid arguments or usage
- `2` I/O error (file not found, cannot write output)
- `3` cryptographic error (wrong key, invalid padding, corrupted data)
