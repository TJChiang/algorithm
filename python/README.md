# algorithm-python


## 開發環境

1. 進入 container 執行 python

```bash
docker compose rum --rm -it python bash
```

2. 建立虛擬環境

```bash
python3 -m venv .venv
```

3. 啟動虛擬環境

```bash
source .venv/bin/activate
```

4. pip 安裝 packages

```bash
pip install ...
pip install -r requirements.txt
```

5. 關閉 venv

```bash
deactivate
```
