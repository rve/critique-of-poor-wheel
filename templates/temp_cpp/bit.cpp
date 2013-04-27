int sum(int k) {
  int ans = 0;
  for (int i = k; i > 0; i -= i & -i)
    ans += a[i];
  return ans;
}

void change(int k,int n,int delta) {
  for (int i = k; i <= n; i += i & -i)
    a[i] += delta;
}
