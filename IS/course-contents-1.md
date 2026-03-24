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