bool GameModelBase::is_moves_left() const
{
    for (int position : player_moves)
    {
        if(position == -1)
        {
            return true;
        }
    }
    return false;
}