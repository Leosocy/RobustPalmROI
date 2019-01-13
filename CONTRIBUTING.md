# Contributing

Contributions are welcome, and they are greatly appreciated! Every little bit helps, and credit will always be given.

You can contribute in many ways:

## Types of Contributions

### Report Bugs

Report bugs at [issues](https://github.com/Leosocy/RobustPalmRoi/issues).

If you are reporting a bug, please include:

- Your operating system name and version.
- Any details about your local setup that might be helpful in troubleshooting.
- Detailed steps to reproduce the bug.

### Submit Feedback

The best way to send feedback is to file an issue at [issues](https://github.com/Leosocy/RobustPalmRoi/issues).

If you are proposing a feature:

- Explain in detail how it would work.
- Keep the scope as narrow as possible, to make it easier to implement.
- Remember that this is a volunteer-driven project, and that contributions are welcome :)

## Get Started!

Ready to contribute? Here's how to set up `RobustPalmRoi` for local development.

1. Fork the [RobustPalmRoi](https://github.com/Leosocy/RobustPalmRoi) repo on Github.
1. Clone your fork locally:
    ```shell
    git clone git@github.com:your_name_here/RobustPalmRoi.git
    ```
1. Create a branch for local development:
    ```shell
    git checkout -b name-of-your-bugfix-or-feature
    ```
    Now you can make your changes locally.
1. When you're done making changes, check that your changes pass the tests and lints:
    ```shell
    ./manage.sh test_and_lint
    ```
    and then it will pull docker image, and run tests and lints in container.
1. Commit your changes and push your branch to GitHub:
    ```shell
    git add .
    git commit -m "Your detailed description of your changes."
    git push origin name-of-your-bugfix-or-feature
    ```
1. Submit a pull request through the GitHub website.

## Pull Request Guidelines

Before you submit a pull request, check that it meets these guidelines:

1. The pull request should include tests and reach the codecov requirement(see in [.codecov.yml](https://github.com/Leosocy/RobustPalmRoi/blob/master/.codecov.yml)).
1. Please follow `Clean Code` standards, and it would be nicer to follow the [Google C++ Code Style](https://blog.leosocy.top/Google%20C++%20Code%20Style/).
