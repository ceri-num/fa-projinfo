# Introduction to GIT

An excellent introduction to git is available here: [GIT-SCM, The entire Pro Git Book](https://git-scm.com/book/en/v2).

## Version Control

## GIT project
In GIT, you have two important notions: the local repository (the one in which you currently work) and remote repositories. Remote repositories are versions of the project that are hosted on the internet/network somewhere else than on your machine. Collaborating with others involves managing these remote repositories and pushing and pulling data to and from them when you need to share work. Some of them can be read-only for your, other read-write.

## GIT Workflow
We recommand you to adopt the *Integration Manager Workflow*. It is a common Git workflow, which involves an integration manager — a single person who commits to the 'blessed' repository. A number of developers then clone from that repository, push to their own independent repositories, and ask the integrator to pull in their changes. This fits well with the role repartition of the project.

![The Integration Manager Workflow](resources/workflow_git.png)
