struct buf {
  int valid;   // has data been read from disk?
  int disk;    // does disk "own" buf? 缓冲区内容是否已交给磁盘
  // 缓存块的标识
  uint dev;    
  uint blockno;

  struct sleeplock lock;
  uint refcnt;    // 引用计数
  struct buf *prev; // LRU cache list
  struct buf *next;
  uchar data[BSIZE];

  uint timestamp; // 时间戳
};

