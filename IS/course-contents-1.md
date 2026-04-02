> Note: This File is NotebookLM Generated
### **Course Curriculum: Information Security**

Based on the provided sources, the following is the comprehensive list of topics and subtopics for preparation, organized by the progression of the course materials.

---

### **1. Foundations of Computer Security**
*   **The Problem Statement**: Why secure communication is challenging.
*   **The Classic Example (Alice and Bob)**: Understanding adversaries:
    *   **Eavesdropping (Eve)**: Threats to confidentiality.
    *   **Tampering (Mallory)**: Threats to integrity.
    *   **Impersonation (Trudy)**: Threats to authentication.
    *   **Denial and Repudiation**: Issues of accountability.
*   **The CIA Triad**: Confidentiality, Integrity, and Availability.
*   **Risk Management Framework**:
    *   **Threats**: Potential dangers or adversaries.
    *   **Vulnerabilities**: Weaknesses that can be exploited.
    *   **Risk Calculation**: $Risk = Threat \times Vulnerability \times Impact$.
*   **Foundational Security Principles (Saltzer & Schroeder)**:
    *   **Least Privilege**.
    *   **Fail-Safe Defaults**.
    *   **Economy of Mechanism** (Simplicity).
    *   **Complete Mediation** (Continuous verification).
    *   **Open Design** (Security should not depend on secrecy).

---

### **2. Identity and Access Management (IAM)**
*   **Authentication Factors**:
    *   **Something You Know**: Passwords and passphrases.
    *   **Something You Have**: Tokens, smart cards, mobile phones.
    *   **Something You Are**: Biometrics (fingerprints, facial features).
*   **Multi-Factor Authentication (MFA)**: Strengthening security by combining factors.
*   **The AAA Framework**:
    *   **Authentication**: Verifying identity.
    *   **Authorization**: Determining permissions (What can you do?).
    *   **Accounting & Auditing**: Creating logs of actions.
*   **Non-Repudiation**: Using digital signatures for cryptographic proof of authorship.
*   **IAM in Modern Defense**: Disrupting credential theft, lateral movement, and data exfiltration.

---

### **3. Security Controls: Types & Categories**
*   **Control Categories (The "How")**:
    *   **Managerial (Administrative)**: Policies, risk management, and training.
    *   **Operational**: Human-driven day-to-day procedures (guard patrols, backups).
    *   **Technical**: Software, firmware, or hardware-based automation (firewalls, encryption).
    *   **Physical**: Tangible barriers (locks, fences, mantraps).
*   **Control Types (The "What")**:
    *   **Preventive**: Blocking unauthorized actions.
    *   **Deterrent**: Psychologically discouraging attackers.
    *   **Detective**: Identifying incidents as they happen.
    *   **Corrective**: Mitigating damage and restoring systems.
    *   **Compensating**: Alternative controls for when primary ones aren't feasible.
    *   **Directive**: Guiding user behaviour through rules.
*   **Defense in Depth**: Layering multiple categories and types for resilience.

---

### **4. The Threat Landscape & Adversaries**
*   **Hierarchy of Adversaries**:
    *   **Nation-State Actors (APTs)**: Sophisticated, well-funded, and patient.
    *   **Organized Cybercriminals**: Professionalized, profit-driven (Ransomware-as-a-Service).
    *   **Hacktivists**: Ideologically or politically motivated.
    *   **Insider Threats**: Malicious, negligent, or compromised trusted individuals.
*   **The Cyber Kill Chain**:
    *   Reconnaissance, Weaponization, Delivery, Exploitation, Installation, Command & Control (C2), Actions on Objectives.
*   **Social Engineering**: Manipulating the "human operating system" (Authority, Urgency, Reciprocity).
*   **Phishing Evolution**: Generation 1 (Spray and Pray) to Generation 4 (Conversational AI).
*   **Vulnerability Lifecycle**:
    *   **Zero-Day**: Unknown to vendor, no patch exists.
    *   **N-Day**: Known to vendor, patch available but potentially unapplied.

---

### **5. Malware Attacks**
*   **Malware Taxonomy (By Propagation)**:
    *   **Viruses**: Self-replicating; requires a host and human action.
    *   **Worms**: Self-replicating; spreads independently across networks.
    *   **Trojans**: Disguised as legitimate software; often serves as a backdoor.
*   **Malware Taxonomy (By Function/Payload)**:
    *   **Ransomware**: Encryption and extortion (Double/Triple/Quadruple Extortion evolution).
    *   **Spyware & Keyloggers**: Silent monitoring and credential capture.
    *   **Rootkits**: Hiding presence at the kernel, boot, or firmware level.
    *   **Botnets**: Networks of "zombie" computers under C2 control (DDoS, spam, mining).
    *   **Logic Bombs**: Triggered by specific conditions.
    *   **Bloatware**: Unwanted pre-installed software.
*   **Advanced Malware Techniques**:
    *   **Multi-Stage Infection Chains**: Droppers, Downloaders, and Payloads.
    *   **Living-off-the-Land (LOTL)**: Using legitimate system tools (PowerShell, WMI) for malicious acts.
    *   **Fileless Malware**: Memory-only attacks that avoid disk detection.

---

### **6. Password Attacks & Mitigations**
*   **Online vs. Offline Attacks**: Direct interaction vs. cracking extracted hashes.
*   **Attack Techniques**:
    *   **Brute Force**: Attempting every combination.
    *   **Dictionary & Wordlist Attacks**: Using common passwords or breach databases.
    *   **Password Spraying**: Trying one common password on many accounts.
    *   **Credential Stuffing**: Exploiting password reuse from data breaches.
    *   **Pass-the-Hash**: Using the password hash directly to authenticate in Windows environments.
*   **Mitigation Strategies**: Account lockout, rate limiting, MFA, and Credential Guard.

---

### **7. Application, Web, and Authorization Attacks**
*   **Application Vulnerabilities**:
    *   **Memory Injection**: Inserting unauthorized code into memory.
    *   **Buffer Overflow**: Writing beyond memory boundaries to hijack control flow.
    *   **Race Conditions & TOCTOU**: Exploiting timing windows between security checks and resource use.
    *   **Malicious Updates**: Weaponizing supply chains (e.g., SolarWinds).
*   **Web Application Attacks**:
    *   **SQL Injection (SQLi)**: Manipulating database queries through input fields.
    *   **Cross-Site Scripting (XSS)**: Reflected, Stored, and DOM-based script injection.
    *   **Request Forgeries**: CSRF (Cross-Site) and SSRF (Server-Side).
*   **Authorization Vulnerabilities**:
    *   **Privilege Escalation**: Vertical (higher access) and Horizontal (same level, different user).
    *   **Insecure Direct Object References (IDOR)**: Accessing resources via predictable identifiers.
    *   **Directory Traversal**: Using `../` sequences to escape the web root.
    *   **File Inclusion**: Local (LFI) and Remote (RFI) file execution.

---

### **8. Network and Cryptographic Attacks**
*   **Network Attacks**:
    *   **Denial of Service (DoS/DDoS)**: Volumetric, Protocol, and Application Layer floods.
    *   **Amplification Attacks**: Exploiting DNS, NTP, or Memcached to multiply traffic.
    *   **On-Path Attacks (MitM)**: Intercepting communications via Rogue APs or ARP poisoning.
    *   **ARP Poisoning**: Forging ARP replies to redirect LAN traffic.
    *   **DNS Attacks**: Cache poisoning, hijacking, and homograph attacks.
*   **Cryptographic Attacks**:
    *   Targeting algorithms (MD5/SHA-1 collisions), implementations (buffer overflows), or key management (poor storage).
    *   **Protocol Attacks**: e.g., Downgrade attacks on TLS.
    *   **Birthday Attacks** & Hash Collisions.

---

### **9. Basic Cryptography**
*   **Core Concepts**: Plaintext, Ciphertext, Encryption, Decryption, Ciphers, and Keys.
*   **Historical Ciphers**: Caesar Cipher and the weakness of frequency analysis.
*   **Modern Cryptography Foundations**:
    *   **Kerckhoffs’s Principle**: Security resides in the key, not the algorithm's secrecy.
    *   **Symmetric Encryption**: Shared-key systems (AES, DES, Block vs. Stream ciphers).
    *   **The One-Time Pad**: Perfect secrecy requirements and practical limitations.
    *   **Computational Security**: Security based on the vast resources required to break a cipher.
    *   **Attack Models**: Ciphertext-Only, Known-Plaintext, Chosen-Plaintext, Chosen-Ciphertext.
    *   **Confusion and Diffusion**: Shannon's principles for strong ciphers.
    *   **Cipher Architectures**: Feistel Networks (DES) vs. SP-Networks (AES).
*   **Digital Signatures**: Process of hashing and encrypting with private keys.

---

### **10. Practical Security Skills**
*   **Penetration Testing Fundamentals**:
    *   Enacting methodologies using Hack The Box (HTB).
    *   Essential tools: `nmap`, `gobuster`, `Metasploit`.
*   **Buffer Overflow Exploitation**:
    *   **Tools**: X64dbg, Process Hacker, PE-Bear, Python/pwntools.
    *   **Methodology**: Identifying vulnerable functions, stack frame analysis, and overwriting return addresses.

---

### **1. Introduction to Block Ciphers**
*   **Definition**: Mapping n-bit plaintext blocks to n-bit ciphertext blocks via an invertible function.
*   **Key Features**:
    *   **Block Size**: Impact on security levels.
    *   **Key Size**: Relationship to key space and overall security.
    *   **Number of Rounds**: Security gains through iteration.
    *   **Encryption Modes**: Procedures for handling messages larger than the block size.

### **2. The Feistel Network**
*   **General Structure**: Specified by block size, number of rounds, and round functions ($f$).
*   **Operational Logic**:
    *   **Encryption**: Iterative processing where each round uses a specific round function and subkey.
    *   **Decryption**: Using the same structure but reversing the round functions and keys.
*   **Adoption**: Used in ciphers like DES, IDEA, and RC5, but notably absent in AES.

### **3. DES Overview and Standards**
*   **NIST and Standards**: The role of NIST in promoting cryptographic standards like FIPS.
*   **History of DES**:
    *   Origin at IBM (Feistel's "Lucifer" cipher).
    *   NBS (now NIST) and NSA involvement in development and adoption in 1977.
    *   Eventual replacement by Rijndael (AES) in 2001.
*   **Fundamental DES Features**:
    *   **Block Size**: 64 bits.
    *   **Key Size**: 56 effective bits (stored as 64 bits with 8 parity bits).
    *   **Rounds**: 16.

### **4. Internal Structure of DES**
*   **Initial and Final Permutations**:
    *   **Initial Permutation (IP)**: Initial bit-level reshuffling of the 64-bit plaintext.
    *   **Final Permutation (IP-1)**: The inverse of the IP applied after the 16th round.
*   **The DES Round Logic**:
    *   Splitting data into Left ($L$) and Right ($R$) 32-bit halves.
    *   **Round Function Components**:
        *   **Expansion Function (E)**: Expanding 32 bits to 48 bits for XORing with the subkey.
        *   **S-Boxes (Substitution Boxes)**: The only non-linear elements; mapping 6-bit inputs to 4-bit outputs through matrix lookups to provide confusion.
        *   **Permutation (P-box)**: A fixed straight permutation of the 32-bit output of the S-boxes.

### **5. DES Key Schedule (Subkey Generation)**
*   **Key Processing**:
    *   **Parity Bit Removal**: Discarding bits 8, 16, ..., 64.
    *   **Permuted Choice 1 (PC-1)**: Selecting and splitting the 56 bits into two 28-bit halves ($C_0$ and $D_0$).
    *   **Left Circular Shifts**: Shifting halves by one or two positions per round depending on the round number.
    *   **Permuted Choice 2 (PC-2)**: Selecting 48 bits from the shifted 56-bit state to create the round subkey ($K_i$).

### **6. DES Decryption**
*   **Mechanism**: Uses the identical algorithm as encryption but applies the 16 subkeys ($K_1$ through $K_{16}$) in reverse order.

### **7. Practical Application: Unix Crypt**
*   **Logic**: Using a password as a DES key to encrypt an all-zeros block for 25 rounds.
*   **Security Features**:
    *   **Salt**: 12-bit random string stored with the password to perturb the expansion function and thwart dictionary attacks.

### **8. Block Cipher Modes of Operation**
*   **Electronic Code Book (ECB)**: Simple, deterministic, and malleable; reveals data patterns and is not recommended for multiple blocks.
*   **Cipher Block Chaining (CBC)**: Uses an Initialization Vector (IV); each block depends on the previous one, providing randomized encryption but sequential processing.
*   **Stream Cipher Constructions using DES**:
    *   **Cipher Feedback (CFB)**: XORs plaintext with the feedback of previous ciphertext; sequential and self-synchronizing.
    *   **Output Feedback (OFB)**: XORs plaintext with a generated pseudo-random stream; limits error propagation.
    *   **Counter Mode (CTR)**: XORs plaintext with encrypted nonces/counters; supports parallel processing and random access.

### **9. Cryptanalysis and Weaknesses**
*   **Structural Weaknesses**:
    *   **Weak Keys**: Four keys that make the encryption function self-inverting (encrypting twice returns the original plaintext).
    *   **Semi-weak Keys**: Six pairs of keys where encryption with one is undone by encryption with the other.
*   **General Attacks**:
    *   **Brute Force**: Exhaustive search of the $2^{56}$ key space; demonstrated historically by the EFF "Deep Crack" in 22 hours.
    *   **Dictionary Attacks**: Matching (P, C) pairs against a lookup table.
    *   **Differential Cryptanalysis**: Analyzing XOR differences between plaintext and ciphertext pairs.
    *   **Linear Cryptanalysis**: Creating linear approximations of the cipher.

### **10. Extensions of DES**
*   **Double DES (2DES)**: Encrypting twice with two different keys; theoretically increases the key to 112 bits.
*   **Meet-in-the-Middle Attack**: Proves 2DES is only slightly more secure than single DES (effective security of $2^{57}$ tests).
*   **Triple DES (3DES/TDEA)**:
    *   Three keying options: three independent keys, two independent keys, or three identical keys.
    *   **Operation**: Encrypt-Decrypt-Encrypt (EDE) sequence.
    *   **Security**: No known practical attacks; option 1 provides 168 bits of key space.

### **11. Strategies for Improving Block Ciphers**
*   **Design Enhancements**: Variable key/block lengths, mixed operators for non-linearity, data-dependent rotations, and key-dependent S-boxes.

---

To understand these concepts, it is helpful to first look at the original **DES (Data Encryption Standard)**, which is like a single lock that uses a 56-bit key to protect your data.

### **Analogies for 2DES and 3DES**

*   **2DES (Double DES):** Think of this as putting your message inside a box and locking it with **Lock A**, then putting that box inside another box and locking it with **Lock B**. You now have two different keys, which seems twice as secure.
*   **3DES (Triple DES):** This is like having a specialized three-stage safe. You **lock** it with Key 1, then use Key 2 to **"unlock"** it (which actually just scrambles the data further because the keys are different), and finally **lock** it again with Key 3.

---

### **How 2DES Was Broken: The "Meet-in-the-Middle" Attack**
Even though 2DES uses two keys (making a 112-bit key), it is not nearly as secure as people expected because of the **Meet-in-the-Middle attack**.

In a normal "brute force" attack, a hacker would have to try every possible combination of Key 1 and Key 2 at the same time ($2^{112}$ combinations), which is impossible with today's computers. However, the Meet-in-the-Middle attack works by **working from both ends simultaneously** if the attacker has one example of a plain message and its encrypted version:

1.  **Work Forward:** The attacker encrypts the plain message with every possible version of **Key 1** and stores all those results in a giant table.
2.  **Work Backward:** The attacker takes the encrypted version and decrypts it with every possible version of **Key 2**.
3.  **Find the Match:** They look for where the two lists "meet in the middle". A match reveals the correct keys.

Because of this trick, the security drops from a massive $2^{112}$ down to about $2^{57}$ tests—which is only slightly harder than breaking a single DES lock.

---

### **Why 3DES uses Encrypt-Decrypt-Encrypt (EDE)**
Triple DES uses a strange sequence: it **Encrypts** with Key 1, **Decrypts** with Key 2, and **Encrypts** again with Key 3. You might wonder why the middle step is "decryption" instead of just another encryption.

The main reason is **backward compatibility**. 

*   **To be 3DES:** You use three different keys ($K_1, K_2, K_3$). The middle "decryption" step doesn't actually unlock anything; it just acts as another layer of scrambling.
*   **To act like old DES:** If you use the **same key** for all three steps ($K_1 = K_2 = K_3$), the first "Encrypt" and the second "Decrypt" **cancel each other out**. This leaves only the final "Encrypt" step active. 

This allowed companies with older DES systems to still communicate with newer 3DES systems just by repeating the same key three times. While 3DES is much slower than newer methods, there are **no known practical attacks** that can break the version using three independent keys.