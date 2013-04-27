int elfhash(char *key) {
  unsigned int h = 0;
  while(*key) {
    h = (h << 4) + *key++;
    unsigned int g=h&0Xf0000000L;
    if (g) h ^= g >> 24;
    h &= ~g;
  }
  return h%MOD;
}
