![ALt text](https://github.com/abdo-skhairi/minitalk/blob/main/mini.jpg)

### **Minitalk Project**  

**Minitalk** is a 42 network project where you create a simple message-passing system using UNIX signals (`SIGUSR1` and `SIGUSR2`). It consists of a **client** and a **server** that communicate via **signals** to send messages.

---

### **1️⃣ How Minitalk Works (Client → Server Messaging)**  

1. **Server Setup**  
   - The server starts and prints its **Process ID (PID)**.  
   - It waits for signals (`SIGUSR1` and `SIGUSR2`) from the client.  

2. **Client Sends a Message**  
   - The client takes a **message and the server’s PID** as arguments.  
   - It converts each character of the message into **binary (8 bits)**.  
   - It sends **each bit** as a signal:  
     - `SIGUSR1` → represents bit **0**  
     - `SIGUSR2` → represents bit **1**  
   - The client sends characters **bit by bit** until the full message is sent.  

3. **Server Receives the Message**  
   - The server catches incoming signals.  
   - It reconstructs each **character from the received bits**.  
   - After receiving 8 bits, it prints the corresponding character.  
   - The process repeats until the full message is received.  

---

### **2️⃣ Example Workflow**  
1️⃣ Start the server:  
```bash
./server
```
➡️ Output: `Server PID: 12345`

2️⃣ Send a message from the client:  
```bash
./client 12345 "Hello!"
```
➡️ The client sends `"Hello!"` **bit by bit** using `SIGUSR1` and `SIGUSR2`.

3️⃣ The server prints the received message:  
```
Hello!
```

---

### **3️⃣ Key Components**
✅ **Signals Used**:  
   - `SIGUSR1` → Bit `0`  
   - `SIGUSR2` → Bit `1`  

✅ **Bitwise Operations**:  
   - The client **shifts** and sends each bit separately.  
   - The server **rebuilds** characters using bitwise operations.  

✅ **Reliability Mechanism** (Bonus):  
   - The server **acknowledges receipt** by sending signals back to the client.  

---
