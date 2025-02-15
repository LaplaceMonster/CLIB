#Git相关命令
使用 SSH 连接本地 Git 和 GitHub 需要几个步骤。下面是详细的操作流程：

1. 生成 SSH 密钥
首先，你需要生成一对 SSH 密钥（公钥和私钥）。如果你已经有密钥对，可以跳过这个步骤。

打开终端并运行以下命令：

bash
复制
编辑
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
这里的 "your_email@example.com" 应该替换为你在 GitHub 上注册的邮箱地址。
该命令会提示你选择保存密钥的路径（默认是 ~/.ssh/id_rsa）。如果你没有特别的需求，可以直接按 Enter 键使用默认路径。
如果有提示输入 passphrase（密码），你可以设置一个密码，也可以直接按 Enter 跳过。
2. 添加 SSH 密钥到 SSH 代理
确保你的 SSH 代理正在运行，并将密钥添加到代理中：

bash
复制
编辑
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa
3. 将公钥添加到 GitHub
接下来，你需要将生成的 SSH 公钥添加到 GitHub 上。

查看生成的公钥内容：
bash
复制
编辑
cat ~/.ssh/id_rsa.pub
复制输出的内容（包括开头的 ssh-rsa 和结尾的邮箱地址）。

登录到 GitHub：
进入 GitHub 的 SSH 密钥设置页面
点击 "New SSH key"
在 "Title" 中输入一个描述性名字（例如 "My Laptop"）
将刚才复制的公钥粘贴到 "Key" 字段
点击 "Add SSH key" 保存
4. 测试 SSH 连接
确保你可以成功通过 SSH 连接到 GitHub：

bash
复制
编辑
ssh -T git@github.com
如果这是你第一次连接 GitHub，系统会提示你确认连接，输入 yes。然后，你应该看到类似以下的消息：

vbnet
复制
编辑
Hi username! You've successfully authenticated, but GitHub does not provide shell access.