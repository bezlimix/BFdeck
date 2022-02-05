
int n;
int a[10000];
int pref[10000];
void setup() {
  Serial.begin(9600);
}
void precalc() {
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] ^ a[i];
    }
}

long long query(int l, int r) {
    if (l > 0) {
        return pref[r] ^ pref[l - 1];
    } else {
        return pref[r];
    }
}
void loop() {
  
for(long x = 999999;x<2147483647;x++){
  Serial.println(x*x);
}}
 
