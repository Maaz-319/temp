1. **Assembly Language (AL) works directly with processor internals**
   Unlike C/Python, where you write high-level instructions, assembly interacts with the CPU’s **registers, instructions, memory, and control flow**.
   → So, to write assembly, you **must know the CPU architecture**.

---

### 🔹 Processor Architecture concepts you need to know:

1. **Registers** – Small memory inside the CPU (very fast). Examples:

   * `AX, BX, CX, DX` (general-purpose registers).
   * You must know their **names, sizes (16-bit, 32-bit, etc.), and usage**.

2. **Instruction Set** – All the commands the CPU understands.
   Example categories:

   * **Data movement**: `MOV`, `LOAD`, `PUSH`, `POP`
   * **Arithmetic/logic**: `ADD`, `SUB`, `AND`
   * **Flow control**: `CALL`, `JMP`, `RET`, `JNZ`
   * **Special instructions**: `CLI`, `STI`

   👉 Even a complex C statement like `A = B + 5*C` is broken down into simple instructions like `MOV`, `ADD`, `MUL`.

3. **Instruction format examples**:

   * `ADD AX, BX` → Add BX into AX.
   * `INC AX` → Increase AX by 1.
   * `PUSH BX` → Save BX onto stack.
   * `MOVSB` → Move string byte.

---

### 🔹 Program demonstration:

**Add 5 + 10 + 15 using assembly.**

* **C style**:

  ```c
  AX = 5;
  BX = 10;
  AX = AX + BX;
  BX = 15;
  AX = AX + BX;
  ```

* **Pseudocode**:

  ```
  MOV 5 to AX
  MOV 10 to BX
  ADD BX to AX
  MOV 15 to BX
  ADD BX to AX
  ```

* **Assembly code (MASM syntax):**

  ```asm
  .MODEL SMALL
  .STACK 100H
  .CODE
  MAIN PROC
      MOV AX, 5
      MOV BX, 10
      ADD AX, BX
      MOV BX, 15
      ADD AX, BX
      MOV AH, 4CH
      INT 21H
  MAIN END
  END MAIN
  ```

👉 This program just calculates **AX = 5 + 10 + 15** and then exits.

---

### 🔹 Program life cycle (how an Assembly program runs):

1. **Editor** – Write code in `.ASM` file (e.g., `p1.asm`).
2. **Assembler (MASM)** – Converts assembly into object code `.obj`.

   ```bash
   masm p1.asm
   ```
3. **Linker** – Converts `.obj` into executable `.exe`.

   ```bash
   link p1.obj
   ```
4. **Run** – Execute the program.

   ```bash
   p1.exe
   ```

---

### 🔹 Debugging Assembly

Using DOS `debug`:

* `R` → View registers (`AX, BX, CX…`).
* `T` → Step through program instruction by instruction.

This shows how the **Instruction Pointer (IP)** moves and executes instructions sequentially.

---

### 🔹 PATH Setting

To avoid typing full paths every time, you add `C:\MASM\BIN` into the system **Environment Variables → PATH**.
So you can run `masm` and `link` from anywhere in CMD.