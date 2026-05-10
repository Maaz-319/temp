Based on the provided information security course materials, here is the comprehensive list of topics and their associated subtopics to be prepared:

### **1. Advanced Encryption Standard (AES)**
*   **Historical Context:** Why the Data Encryption Standard (DES) was no longer sufficient and the NIST competition that led to the selection of Rijndael.
*   **Core Components:** 
    *   Fixed block size (128 bits).
    *   Variable key sizes (128, 192, or 256 bits) and their corresponding rounds (10, 12, or 14).
*   **AES Architecture:**
    *   **The State Matrix:** The 4x4 matrix of bytes used as the working canvas.
    *   **Key Expansion:** Generating unique Round Keys using SubWord, RotWord, and Round Constants (Rcon).
*   **The Encryption Process:**
    *   **Initial Step:** AddRoundKey (initial whitening).
    *   **The Four Transformations:** ByteSub (confusion), ShiftRow (permutation), MixColumn (diffusion), and AddRoundKey (key injection).
    *   **Final Round:** Structural differences including the omission of the MixColumn step.
*   **Real-World Applications:** Wireless security (WPA2/WPA3), Web & VPNs (TLS/SSL), and file encryption.

### **2. RSA (Asymmetric) Encryption**
*   **Mathematical Foundations:**
    *   **Modular Arithmetic:** "Clock math" and the concept of remainders.
    *   **Number Theory Building Blocks:** Prime numbers, Greatest Common Divisor (GCD), coprime numbers, and Euler's Totient Function $\phi(n)$.
*   **Key Generation Process:** Selecting primes, computing the modulus ($n$), calculating $\phi(n)$, and deriving public ($e$) and private ($d$) exponents.
*   **Encryption and Decryption Mechanics:** Mathematical walkthrough of the transformation process and the proof based on Euler's Theorem.
*   **Security Analysis:** The computational hardness of factoring large numbers versus the ease of multiplication (One-Way Functions).

### **3. Block Cipher Modes of Operation**
*   **The Core Problem:** Securely encrypting data longer than a single block.
*   **Classic Modes:**
    *   **Electronic Codebook (ECB):** Its mechanism and the critical security flaw of pattern leakage.
    *   **Cipher Block Chaining (CBC):** Block interdependence, Initialization Vectors (IVs), sequential nature, and error propagation.
*   **Stream Cipher Principles:** Transforming block ciphers into stream ciphers via keystream generation and XOR operations.
*   **Stream Modes:**
    *   **Cipher Feedback (CFB):** Feedback from ciphertext and self-synchronization properties.
    *   **Output Feedback (OFB):** Feedback from keystream and zero error propagation.
    *   **Counter Mode (CTR):** Full parallelization, random access, and its status as the modern choice.
*   **Advanced Concepts:** Authenticated Encryption with Associated Data (AEAD) modes like GCM and CCM.

### **4. Governance, Risk, and Compliance (GRC)**
*   **Foundational GRC:** Definitions and the importance of integrating governance, risk, and compliance.
*   **Information Security Governance:** Strategic alignment, value delivery, performance measurement, and risk optimisation.
*   **Roles and Responsibilities:** Accountability from executive leadership (CEO, CISO, Board) to individual employees.
*   **Risk Management Process:** Systematic identification, analysis (qualitative vs. quantitative), evaluation, and treatment strategies (Avoid, Mitigate, Transfer, Accept).
*   **Security Frameworks and Standards:** 
    *   **ISO/IEC 27001:** Information Security Management Systems (ISMS) and the Plan-Do-Check-Act cycle.
    *   **NIST Cybersecurity Framework (CSF):** Identify, Protect, Detect, Respond, Recover.
    *   **NIST SP 800-53:** Comprehensive catalog of security and privacy controls.
*   **Compliance and Auditing:** Internal vs. external audit types, common regulations (PCI-DSS, HIPAA, FISMA, GDPR), and the audit lifecycle.

### **5. Resilience and Recovery (BC/DR)**
*   **Business Continuity (BC) vs. Disaster Recovery (DR):** Differences in goals, scope, and timeframes.
*   **Business Impact Analysis (BIA):** Identifying critical functions and defining Recovery Time Objectives (RTO) and Recovery Point Objectives (RPO).
*   **Recovery Strategies:**
    *   **Backup Methods:** Full, Incremental, and Differential backups.
    *   **The 3-2-1 Backup Rule:** Maintaining redundancy.
    *   **Recovery Sites:** Hot, Warm, and Cold site readiness.
*   **Availability Levels:** High Availability (99.9%) vs. Fault Tolerance (99.999%).
*   **Testing and Validation:** Tabletop exercises, simulations, and full-interruption tests.

### **6. Data Privacy and Protection**
*   **The Privacy Paradox:** Balancing data utility with individual rights (Control, Context, Dignity).
*   **Privacy Violations:** Real-world harms (career, financial, political) and the "Data Shadow" journey.
*   **Traditional Anonymization Pitfalls:** Why pseudonymization and generalization fail due to linkage/re-identification attacks.
*   **Differential Privacy (DP):** The paradigm shift to adding mathematical noise, the privacy budget ($\epsilon$), and real-world implementations.
*   **Privacy-Enhancing Technologies (PETs):** Password managers, encrypted communication (Signal, ProtonMail), and browser extensions.
*   **Regulatory Landscape:** GDPR, CCPA, and professional career paths.

### **7. Secure Software Development and Deployment (SSDLC)**
*   **The "Shift Left" Philosophy:** Integrating security throughout the SDLC from planning to maintenance.
*   **Secure Coding Practices:** Input validation (allow-lists), context-specific output encoding (XSS prevention), and fail-secure error handling.
*   **Frameworks and Methodologies:** Microsoft SDL, OWASP SAMM maturity models, and DevSecOps automation.
*   **Application Security Testing (AST):** Static (SAST), Dynamic (DAST), and Interactive (IAST) approaches.

### **8. OWASP Top 10 for LLMs and AI Systems**
*   **LLM-Specific Attack Surfaces:** Prompts, RAG pipelines, and autonomous agency.
*   **The Top 10 Risks:**
    *   **Prompt Injection:** Hijacking model instructions.
    *   **Sensitive Information Disclosure:** Unintentional revelation of private data.
    *   **Supply Chain Vulnerabilities:** Third-party component risks.
    *   **Data and Model Poisoning:** Malicious training data.
    *   **Improper Output Handling:** Injection attacks via model output.
    *   **Excessive Agency:** Over-permissioned AI agents.
    *   **System Prompt Leakage:** Exposure of confidential developer instructions.
    *   **Vector and Embedding Weaknesses:** Security of the RAG retrieval pipeline.
    *   **Misinformation:** Dealing with hallucinations.
    *   **Unbounded Consumption:** Managing infrastructure costs and DoS risks.

### **9. Vulnerability Assessment and Penetration Testing (VAPT)**
*   **Vulnerability Management Lifecycle:** Discover, Prioritise, Assess, Report, Remediate, Verify.
*   **Vulnerability Scanning:** Tools (Nessus, Qualys, OpenVAS) and Authenticated vs. Unauthenticated scanning.
*   **Penetration Testing Methodology:** Planning & Reconnaissance, Scanning, Exploitation, Post-Exploitation, and Reporting.
*   **Testing Scopes:** Black-Box, White-Box, and Grey-Box testing.
*   **Threat Hunting:** Proactive search for advanced persistent threats (APTs) that evade automated controls.

### **10. Digital Forensics and Incident Response (DFIR)**
*   **Core Concepts:** Distinguishing between IR (operational containment) and Digital Forensics (scientific investigation).
*   **NIST Incident Response Lifecycle:** Preparation, Detection & Analysis, Containment, Eradication & Recovery, and Post-Incident Activity.
*   **Forensics Fundamentals:** The Order of Volatility (CPU to Backups) and the Chain of Custody.
*   **Data Acquisition and Analysis:** Live vs. Static forensics, Disk, Memory, Network, and Log analysis.
*   **Incident Management:** Team roles and secure out-of-band communication protocols.