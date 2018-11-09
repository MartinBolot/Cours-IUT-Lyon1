import React, { Component } from 'react';

class LeftSide extends Component {
  render() {
    return (
      <div>{this.props.children}</div>
    );
  }
}

export default LeftSide;
