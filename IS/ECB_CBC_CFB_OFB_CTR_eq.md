# ECB (Electronic Codebook)

## Encryption

```math
C_i = E_K(P_i)
```

## Decryption

```math
P_i = D_K(C_i)
```

---

# CBC (Cipher Block Chaining)

## Encryption

```math
C_i = E_K(P_i \oplus C_{i-1})
```

```math
C_0 = IV
```

## Decryption

```math
P_i = D_K(C_i) \oplus C_{i-1}
```

---

# CFB (Cipher Feedback)

## Encryption

```math
C_i = P_i \oplus E_K(C_{i-1})
```

```math
C_0 = IV
```

## Decryption

```math
P_i = C_i \oplus E_K(C_{i-1})
```

---

# OFB (Output Feedback)

## Encryption

```math
O_i = E_K(O_{i-1})
```

```math
C_i = P_i \oplus O_i
```

```math
O_0 = IV
```

## Decryption

```math
P_i = C_i \oplus O_i
```

---

# CTR (Counter Mode)

## Encryption

```math
C_i = P_i \oplus E_K(CTR_i)
```

## Decryption

```math
P_i = C_i \oplus E_K(CTR_i)
```

```math
CTR_i = Nonce \parallel i
```