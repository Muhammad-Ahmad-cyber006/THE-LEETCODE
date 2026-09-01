class Solution 
{
public:
    using VB=vector<bool>;
    using VVB=vector<VB>;
    using VVVB=vector<VVB>;
    using VVVVB=vector<VVVB>;

    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};

    struct State
    {
        int row;
        int col;
        int energyLeft;
        int collectedMask;
    };

    int minMoves(vector<string>& classroom,int energy) 
    {
        int m=classroom.size();
        int n=classroom[0].size();
        int maxEnergy=energy;
        int litterBit[20][20];
        int litterCount=0;
        int startR=0,startC=0;

        // Har litter ko ek unique bit number de rahe hain
        for(int r=0;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                litterBit[r][c]=-1;
                if(classroom[r][c]=='S')
                {
                    startR=r;
                    startC=c;
                }
                else if(classroom[r][c]=='L')
                {
                    litterBit[r][c]=litterCount++;
                }
            }
        }

        // Agar litter hi nahi hai
        if(litterCount==0)
            return 0;

        // Saara litter collect hone ka mask
        int allCollected=(1<<litterCount)-1;

        // visited[row][col][energy][mask]
        VVVVB visited(m,VVVB(n,VVB(maxEnergy+1,VB(1<<litterCount,false))));

        queue<State> que;
        que.push({startR,startC,maxEnergy,0});
        visited[startR][startC][maxEnergy][0]=true;

        int moves=0;

        while(!que.empty())
        {
            int currSize=que.size();

            while(currSize--)
            {
                State curr=que.front();
                que.pop();

                // Saara litter collect ho gaya
                if(curr.collectedMask==allCollected)
                    return moves;

                // Energy khatam hai
                if(curr.energyLeft==0)
                    continue;

                for(auto &dir:directions)
                {
                    int nextRow=curr.row+dir[0];
                    int nextCol=curr.col+dir[1];

                    // Boundary check
                    if(nextRow<0||nextRow>=m||nextCol<0||nextCol>=n)
                        continue;

                    char cell=classroom[nextRow][nextCol];

                    // Wall
                    if(cell=='X')
                        continue;

                    int nextEnergy=curr.energyLeft-1;
                    int nextCollectedMask=curr.collectedMask;

                    // Litter collect karo
                    if(cell=='L')
                    {
                        nextCollectedMask|=(1<<litterBit[nextRow][nextCol]);
                    }

                    // Recharge cell par energy full ho jayegi
                    if(cell=='R')
                        nextEnergy=maxEnergy;

                    // Agar state pehle visit nahi hui
                    if(!visited[nextRow][nextCol][nextEnergy][nextCollectedMask])
                    {
                        visited[nextRow][nextCol][nextEnergy][nextCollectedMask]=true;
                        que.push({nextRow,nextCol,nextEnergy,nextCollectedMask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};