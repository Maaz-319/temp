# Comprehensive Security Assessment Report: OWASP Juice Shop (v20.2.0)

## 1. Executive Summary
An authorized security assessment and penetration test was conducted against the OWASP Juice Shop application (`http://juice-shop:3000` / `172.17.0.2:3000`). The assessment successfully mapped the application architecture, identified key API endpoints, and evaluated authentication, input validation, and business logic flows. Two high-impact vulnerabilities were identified, validated through controlled proof-of-concept testing, and documented with complete technical evidence:
1. **SQL Injection (CWE-89)** within the product search REST API endpoint.
2. **Information Disclosure (CWE-548)** via an exposed, unauthenticated public FTP directory leaking sensitive configuration, backup, and credential database files.

This report consolidates technical findings, severity ratings, CWE classifications, and actionable remediation strategies to secure the application.

---

## 2. Target & Architectural Overview
*   **Target Application:** OWASP Juice Shop (v20.2.0)
*   **Target URL / IP:** `http://juice-shop:3000` (`172.17.0.2:3000`)
*   **Backend Stack:** Node.js, Express (^4.22.1), SQLite, REST API
*   **Frontend Stack:** Angular Single Page Application (SPA)
*   **Security Headers Observed:** `Access-Control-Allow-Origin: *`, `X-Content-Type-Options: nosniff`, `X-Frame-Options: SAMEORIGIN`

---

## 3. Detailed Vulnerability Findings & Proof-of-Concept Evidence

### 3.1 SQL Injection (CWE-89)
*   **Severity:** High / Critical
*   **Affected Endpoint:** `GET /rest/products/search?q=`
*   **Description:** The application accepts user input via the `q` parameter and directly concatenates it into an underlying SQLite database query (`SELECT * FROM Products WHERE ((name LIKE '%{q}%' OR description LIKE '%{q}%') AND deletedAt IS NULL)`). This lack of parameterization allows arbitrary SQL command injection.
*   **Proof-of-Concept:**
    *   **Request:** `GET /rest/products/search?q=%27%29%29%20OR%201=1-- HTTP/1.1`
    *   **Result:** Bypasses search restrictions and successfully extracts the complete product catalog (56 items, ~21.5 KB), including unreleased or soft-deleted records.
*   **Impact:** Complete search filter bypass, unauthorized database enumeration, and potential data exfiltration.

### 3.2 Information Disclosure / Public Directory Listing (CWE-548)
*   **Severity:** Medium / High
*   **Affected Endpoint:** `GET /ftp/`
*   **Description:** The web server exposes an unauthenticated, publicly indexable directory (`/ftp`) containing sensitive internal project files, backups, and credentials.
*   **Exposed Artifacts:**
    *   `incident-support.kdbx`: KeePass 2 password database containing support credentials.
    *   `acquisitions.md`: Confidential corporate acquisition plans.
    *   `announcement_encrypted.md` & `encrypt.pyc`: Encrypted announcement and associated Python bytecode compilation script.
    *   `suspicious_errors.yml`: Backend error signature configuration rules.
    *   `package.json.bak` / `package-lock.json.bak`: Dependency configuration backups exposing backend module versions.
*   **Impact:** Exposure of sensitive credentials, internal intellectual property, and architectural details aiding further attacks.

---

## 4. Strategic Recommendations & Remediation Roadmap

1. **Remediate SQL Injection (CWE-89):**
   * Migrate all database queries from dynamic string concatenation to parameterized queries, prepared statements, or secure ORM query builders (e.g., Sequelize parameterized finders).
   * Implement strict input validation and sanitization for all search and filter parameters.

2. **Secure Directory Listings (CWE-548):**
   * Disable public directory indexing in Express middleware (e.g., disable `serveIndex` on `/ftp`).
   * Remove all sensitive artifacts (`.kdbx`, `.bak`, `.pyc`, markdown documents) from web-accessible directories.

3. **General Hardening:**
   * Enforce least-privilege access controls across all REST endpoints.
   * Implement robust monitoring and logging for anomalous database query patterns and unauthorized file access attempts.