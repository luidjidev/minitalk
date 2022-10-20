# Minitalk
### The purpose of this project is to code a small data exchange program using UNIX signals. 
The objective was to create a communication program in the form of a **client** and a **server**.
The **server** must be started first and print the **PID.**
Then we start the **client** and it takes two parameters

 - **Server PID**
 - **String to send to server**
 
 We can only use two signals, **SIGUSR1** and **SIGUSR2**.
 
 To try the code, you need to:
 

    git clone https://github.com/luidjidev/minitalk.git
    cd minitalk
    make all
Any question or bug, feel free to reach me on slack **(luisfern)** or on discord **(Luidji#0910)** :).
