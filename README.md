# realtimesystems_exercise2

auf2_1
Verwaister Kindprozess:

„Beendet sich der Elternprozess vor dem Kindprozess, dann adoptiert der Init
Prozess (PID 1) den Kindprozess und wird zu seinem neuen Elternprozess.“
a) Schreiben Sie ein Programm, um diese Aussage zu verifizieren.
b) Erweitern sie den Elternprozess um einen Exithandler, der den String
"Goodbye" gefolgt vom dem Namen des Prozesseigentümer ausgibt.

auf2_2
Zombies:

Schreiben Sie ein Programm zombie welches k Zombieprozesse generiert. Die
Anzahl k soll als Kommandozeilenparameter übergeben werden. Überprüfen Sie
mit dem Kommando ps den Erfolg Ihres Programms.
Für k = −1 soll das Programm soviel Zombieprozesse wir möglich generieren.
Versuchen Sie ein reguläres Programm zu öffnen sobald Ihr Programm keine weiteren
Zombieprozesse mehr generieren kann. Wie erklären Sie sich das Verhalten
des Systems?

auf2_3
Prozess Environment:

Erstellen Sie ein Programm das interaktiv das Ändern bzw. Erfragen der EnvironmentVariablen
ermöglicht.
---------------------
Environment-List Menu
---------------------
[1]: Print environment list
[2]: Print environment entry (getenv)
[3]: Add environment entry (putenv)
[4]: Modify environment entry (setenv)
[5]: Remove environment entry (unsetenv)
[0]: End
(Hinweis: Verwenden sie die Funktion readline() oder getline um Benutzereingaben
einzulesen. In Ihrem Makefile können Sie die Bibliothek libreadline
als Zutat -lreadline hinzufügen.)
