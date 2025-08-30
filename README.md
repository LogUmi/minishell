<div align="center">
  <h2>minishell - 42 project</h2>
  <img src="./bin/minishell.png"  />
  <br>
</div>
# 🐚 Minishell

![Language](https://img.shields.io/badge/language-C-blue)
![Norminette](https://img.shields.io/badge/norminette-passed-brightgreen)
![42](https://img.shields.io/badge/school-42-black)
![Status](https://img.shields.io/badge/status-in%20progress-yellow)

> Une réimplémentation d’un shell UNIX minimaliste en C, réalisée dans le cadre du cursus **École 42**.  
> L’objectif est de comprendre les mécanismes bas-niveau d’un shell (fork, exec, pipes, signaux...).

---

## 📖 Sommaire
- [Description](#-description)
- [Fonctionnalités](#-fonctionnalités)
- [Installation](#-installation)
- [Utilisation](#-utilisation)
- [Architecture](#-architecture)
- [Exemples](#-exemples)
- [Roadmap](#-roadmap)
- [Crédits](#-crédits)
- [Licence](#-licence)

---

## 📝 Description
`minishell` est un shell simplifié qui imite le comportement de `bash`.  
Il permet d’exécuter des commandes, de gérer les redirections, les pipes et certaines builtins.

---

## ✨ Fonctionnalités
- ✅ Exécution de commandes avec `execve`
- ✅ Gestion des pipes `|`
- ✅ Redirections `>`, `<`, `>>`
- ✅ Variables d’environnement
- ✅ Gestion des signaux `Ctrl-C`, `Ctrl-D`, `Ctrl-\`
- ✅ Builtins (`cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit`)
- 🚧 Expansions avancées (en cours)

---

## ⚙️ Installation
Prérequis :  
- OS : Linux ou macOS  
- Compilateur C compatible (gcc, clang)  
- `make`

```bash
git clone https://github.com/<ton-pseudo>/minishell.git
cd minishell
make
./minishell
```

---

## 🖥 Utilisation
Exemple d’exécution :

```bash
$ ./minishell
minishell> echo "Hello World"
Hello World
minishell> ls -l | grep minishell > output.txt
minishell> exit
```

---

## 📂 Architecture

```
.
├── include/        # Fichiers headers (.h)
├── src/            # Code source (.c)
│   ├── builtins/
│   ├── exec/
│   ├── parsing/
│   ├── utils/
├── Makefile
└── README.md
```

---

## 🔎 Exemples
- `ls -la | grep .c > sources.txt`
- `echo "Hello $USER"`
- `cat < input.txt | grep error >> log.txt`

---

## 🚀 Roadmap
- [ ] Support des opérateurs logiques `&&` et `||`
- [ ] Ajout de l’historique des commandes
- [ ] Complétion automatique

---

## 👤 Crédits
Projet réalisé par **Loïc Gérard** – [École 42 Perpignan](https://42perpignan.fr).  
📧 Contact : loic.gerard4@…  

---

## 📜 Licence
Ce projet est sous licence MIT. Vous pouvez l’utiliser, le modifier et le distribuer librement.
